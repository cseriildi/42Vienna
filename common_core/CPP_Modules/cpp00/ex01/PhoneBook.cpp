/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:36:54 by icseri            #+#    #+#             */
/*   Updated: 2024/11/07 15:43:21 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NOLINTBEGIN(bugprone-easily-swappable-parameters, cppcoreguidelines-pro-bounds-constant-array-index, readability-magic-numbers, cppcoreguidelines-avoid-magic-numbers)

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : _contactCount(0) {}
PhoneBook::~PhoneBook() {}

void	PhoneBook::setContact(const std::string& firstName,
								const std::string& lastName,
								const std::string& nickname,
								const std::string& phoneNumber,
								const std::string& darkestSecret)
{
	Contact contact;
	
	contact.setFirstName(firstName);
	contact.setLastName(lastName);
	contact.setNickname(nickname);
	contact.setPhoneNumber(phoneNumber);
	contact.setDarkestSecret(darkestSecret);

	_shiftContacts();
	this->_contacts[0] = contact;
	if (this->_contactCount < PhoneBook::MAXCONTACTCOUNT)
		this->_contactCount++;
}
int		PhoneBook::getContactCount(void) const {return this->_contactCount;}
Contact	PhoneBook::getContact(int index) const {return this->_contacts[index];}

void	PhoneBook::_shiftContacts(void)
{
	for (int i = PhoneBook::MAXCONTACTCOUNT - 1; i > 0; i--)
		this->_contacts[i] = this->_contacts[i - 1];
}

void	PhoneBook::printContact(int index) const
{
	Contact contact;

	contact = getContact(index);
	std::cout << "First Name: " << contact.getFirstName() << "\n";
	std::cout << "Last Name: " << contact.getLastName() << "\n";
	std::cout << "Nickname: " << contact.getNickname() << "\n";
	std::cout << "Phone Number: " << contact.getPhoneNumber() << "\n";
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << "\n";
}

void	PhoneBook::printPhonebook(void) const
{
	std::cout << "|";
	print_field("Index", PhoneBook::BOXLENGTH);
	std::cout << "|";
	print_field("First Name", PhoneBook::BOXLENGTH);
	std::cout << "|";
	print_field("Last Name", PhoneBook::BOXLENGTH);
	std::cout << "|";
	print_field("Nickname", PhoneBook::BOXLENGTH);
	std::cout << "|\n";

	for (int i = 0; i < 4 * PhoneBook::BOXLENGTH + 5; i++)
		std::cout << "-";
	std::cout << "\n";
	for (int i = 0; i < this->_contactCount; i++)
	{
		std::cout << "|";
		print_field(ft_itoa(i), PhoneBook::BOXLENGTH);
		std::cout << "|";
		print_field(this->_contacts[i].getFirstName(), PhoneBook::BOXLENGTH);
		std::cout << "|";
		print_field(this->_contacts[i].getLastName(), PhoneBook::BOXLENGTH);
		std::cout << "|";
		print_field(this->_contacts[i].getNickname(), PhoneBook::BOXLENGTH);
		std::cout << "|" << "\n";
		for (int i = 0; i < 4 * PhoneBook::BOXLENGTH + 5; i++)
			std::cout << "-";
		std::cout << "\n";
	}
}

void	print_field(const std::string& field, int len)
{
	if (len <= 0)
		return;
	if (field.length() <= (long unsigned int)len)
		std::cout << std::setw(len) << field;
	else
		std::cout << field.substr(0, len - 1) << ".";

}

std::string	ft_itoa(int n)
{
	std::stringstream ss;
	ss << n;
	return ss.str();
}

//NOLINTEND(bugprone-easily-swappable-parameters, cppcoreguidelines-pro-bounds-constant-array-index, readability-magic-numbers, cppcoreguidelines-avoid-magic-numbers)
