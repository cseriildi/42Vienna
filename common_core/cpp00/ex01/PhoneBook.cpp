/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:36:54 by icseri            #+#    #+#             */
/*   Updated: 2024/09/08 12:46:11 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
	: _contactCount(0)
{
}

PhoneBook::~PhoneBook()
{
}

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
	if (this->_contactCount < this->_MaxContactCount)
		this->_contactCount++;
}
int		PhoneBook::getContactCount(void) const
{
	return this->_contactCount;
}

Contact	PhoneBook::getContact(int index) const
{
	return this->_contacts[index];
}

void	PhoneBook::_shiftContacts(void)
{
	for (int i = this->_MaxContactCount - 1; i > 0; i--)
		this->_contacts[i] = this->_contacts[i - 1];
}

void	PhoneBook::printContact(int index) const
{
	Contact contact;

	contact = getContact(index);
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

void	PhoneBook::printPhonebook(void) const
{
	std::cout << "|";
	print_field("Index", this->_BoxLength);
	std::cout << "|";
	print_field("First Name", this->_BoxLength);
	std::cout << "|";
	print_field("Last Name", this->_BoxLength);
	std::cout << "|";
	print_field("Nickname", this->_BoxLength);
	std::cout << "|" << std::endl;

	for (int i = 0; i < 4 * this->_BoxLength + 5; i++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < this->_contactCount; i++)
	{
		std::cout << "|";
		print_field(ft_itoa(i), this->_BoxLength);
		std::cout << "|";
		print_field(this->_contacts[i].getFirstName(), this->_BoxLength);
		std::cout << "|";
		print_field(this->_contacts[i].getLastName(), this->_BoxLength);
		std::cout << "|";
		print_field(this->_contacts[i].getNickname(), this->_BoxLength);
		std::cout << "|" << std::endl;
		for (int i = 0; i < 4 * this->_BoxLength + 5; i++)
			std::cout << "-";
		std::cout << std::endl;
	}
}

void	print_field(const std::string& field, int len)
{
	if (len <= 0)
		return;
	if (field.length() <= len)
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
