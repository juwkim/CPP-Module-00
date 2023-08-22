/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 02:19:39 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/23 04:08:04 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void):
	mContactIndex(0),
	mContactSize(0)
{
}

PhoneBook::~PhoneBook(void) { }

void	PhoneBook::Add(void)
{
	Contact &contact = mContact[mContactIndex];

	contact.setFirstName(ReadContactMember("First name"));
	contact.setLastName(ReadContactMember("Last name"));
	contact.setNickName(ReadContactMember("Nick name"));
	contact.setPhoneNumber(ReadContactMember("Phone number"));
	contact.setDarkestSecret(ReadContactMember("Darkest secret"));
	if (mContactSize < mContactCapacity)
		++mContactSize;
	if (mContactIndex == mContactCapacity - 1)
		mContactIndex = 0;
	else
		++mContactIndex;
}

const std::string PhoneBook::ReadContactMember(const std::string& ContactMember) const
{
	std::string	str;
	std::string::size_type	s, e;

	while (true)
	{
		std::cout << ContactMember << ": ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			exit(EXIT_FAILURE);
		s = str.find_first_not_of(" \f\n\r\t\v");
		e = str.find_last_not_of(" \f\n\r\t\v");
		if (s != std::string::npos && e != std::string::npos)
			break;
	}
	return (str.substr(s, e - s + 1));
}

void	PhoneBook::Search(void) const
{
	if (mContactSize == 0) {
		std::cout << "Empty set" << '\n';
		return;
	}
	ShowPhoneBook();
	int idx; std::cin >> idx;
	if (std::cin.eof() == true)
		exit(EXIT_SUCCESS);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (std::cin.fail() == true) {
		std::cin.clear();
		std::cout << "Invalid index" << '\n';
		return;
	}
	if (idx < 0 || idx >= mContactSize) {
		std::cout << "Invalid index" << '\n';
		return;
	}
	mContact[idx].ShowContact();
}

void	PhoneBook::ShowPhoneBook(void) const
{
	for (int i = 0; i < mContactSize; ++i)
	{
		std::cout << std::setw(10) << i;
		mContact[i].ShowContactBrief();
	}
}
