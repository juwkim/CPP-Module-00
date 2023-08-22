/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 02:14:40 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/23 03:44:20 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	Add(void);
		void	Search(void) const;
	private:
		int					mContactIndex;
		int					mContactSize;
		static const int	mContactCapacity = 8;
		class Contact		mContact[mContactCapacity];
		const std::string	ReadContactMember(const std::string& ContactMember) const;
		void				ShowPhoneBook(void) const;
};
