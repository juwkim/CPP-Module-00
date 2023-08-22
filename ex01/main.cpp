/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 02:22:51 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/23 02:29:12 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;

	while (1)
	{
		std::cout << "Usage: ADD | SEARCH | EXIT" << '\n';
		std::string	cmd; std::getline(std::cin, cmd);
		if (std::cin.eof() == true)
			break;
		if (cmd == "EXIT")
			break ;
		if (cmd == "ADD")
			phonebook.Add();
		else if (cmd == "SEARCH")
			phonebook.Search();
	}
	return (EXIT_SUCCESS);
}
