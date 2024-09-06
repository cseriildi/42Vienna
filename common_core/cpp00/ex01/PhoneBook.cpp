/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:36:54 by icseri            #+#    #+#             */
/*   Updated: 2024/09/06 16:02:56 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contact_count(0)
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::set_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	Contact contact;
	
	contact.set_first_name(first_name);
	contact.set_last_name(last_name);
	contact.set_nickname(nickname);
	contact.set_phone_number(phone_number);
	contact.set_darkest_secret(darkest_secret);

	shift_contacts();
	this->contacts[0] = contact;
	if (this->contact_count < this->max_contact_count)
		this->contact_count++;
}
int		PhoneBook::get_contact_count(void)
{
	return this->contact_count;
}

Contact	PhoneBook::get_contact(int index)
{
	return this->contacts[index];
}

void	PhoneBook::shift_contacts(void)
{
	for (int i = this->max_contact_count - 1; i > 0; i--)
		this->contacts[i] = this->contacts[i - 1];
}

void	PhoneBook::print_contact(int index)
{
	Contact contact;

	contact = get_contact(index);
	std::cout << "First Name: " << contact.get_first_name() << std::endl;
	std::cout << "Last Name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone Number: " << contact.get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_darkest_secret() << std::endl;
}

void	PhoneBook::print_phonebook(void)
{
	std::cout << "|";
	print_field("Index", this->box_length);
	std::cout << "|";
	print_field("First Name", this->box_length);
	std::cout << "|";
	print_field("Last Name", this->box_length);
	std::cout << "|";
	print_field("Nickname", this->box_length);
	std::cout << "|" << std::endl;

	for (int i = 0; i < 4 * this->box_length + 5; i++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < this->contact_count; i++)
	{
		std::cout << "|";
		print_field(std::to_string(i), this->box_length);
		std::cout << "|";
		print_field(this->contacts[i].get_first_name(), this->box_length);
		std::cout << "|";
		print_field(this->contacts[i].get_last_name(), this->box_length);
		std::cout << "|";
		print_field(this->contacts[i].get_nickname(), this->box_length);
		std::cout << "|" << std::endl;
		for (int i = 0; i < 4 * this->box_length + 5; i++)
			std::cout << "-";
		std::cout << std::endl;
	}
}

void	print_field(std::string field, int len)
{
	if (len <= 0)
		return;
	if (field.length() <= len)
		std::cout << std::setw(len) << field;
	else
		std::cout << field.substr(0, len - 1) << ".";

}
