/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 01:25:43 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/23 02:07:11 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	printToUpper(const std::string& str);

int	main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
		return (0);
	}
	for (int i = 1; i < argc; ++i)
		printToUpper(argv[i]);
	std::cout << '\n';
	return (0);
}

static void	printToUpper(const std::string& str)
{
	for (std::string::const_iterator it = str.begin(), end = str.end(); it != end; ++it)
		std::cout << static_cast<char>(std::toupper(*it));
}