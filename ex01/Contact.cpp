/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 02:20:19 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/23 03:46:41 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

void Contact::setFirstName(const std::string& firstName) {
	mFirstName = firstName;
}

void Contact::setLastName(const std::string& lastName) {
	mLastName = lastName;
}

void Contact::setNickName(const std::string& nickName) {
	mNickName = nickName;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
	mPhoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
	mDarkestSecret = darkestSecret;
}

void	Contact::ShowContactBrief(void) const
{
	std::cout << " | ";
	showMember(mFirstName);
	std::cout << " | ";
	showMember(mLastName);
	std::cout << " | ";
	showMember(mNickName);
	std::cout << '\n';
}

void	Contact::ShowContact(void) const
{
	std::cout << "first name : " << mFirstName << '\n';
	std::cout << "last name : " << mLastName << '\n';
	std::cout << "nickname : " << mNickName << '\n';
	std::cout << "phone number: " << mPhoneNumber << '\n';
	std::cout << "darkest_secret : " << mDarkestSecret << '\n';
}

void	Contact::showMember(const std::string& member) const
{
	if (member.length() > 10)
		std::cout << member.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << member;
}
