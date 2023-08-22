/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 02:17:50 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/23 03:43:11 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		void	setFirstName(const std::string &firstName);
		void	setLastName(const std::string &lastName);
		void	setNickName(const std::string &nickName);
		void	setPhoneNumber(const std::string &phoneNumber);
		void	setDarkestSecret(const std::string &darkestSecret);
		void	ShowContactBrief(void) const;
		void	ShowContact(void) const;
	private:
		std::string	mFirstName;
		std::string	mLastName;
		std::string	mNickName;
		std::string	mPhoneNumber;
		std::string	mDarkestSecret;
		void	showMember(const std::string& member) const;
};