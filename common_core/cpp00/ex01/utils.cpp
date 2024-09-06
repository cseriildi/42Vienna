/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:13:39 by cseriildii        #+#    #+#             */
/*   Updated: 2024/09/06 16:03:58 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	add_contact(PhoneBook &my_phonebook)
{
	std::string first_name = get_data("First Name");
	std::string last_name = get_data("Last Name");
	std::string nickname = get_data("Nickname");
	std::string phone_number = get_data("Phone Number");
	std::string darkest_secret = get_data("Darkest Secret");

	my_phonebook.set_contact(first_name, last_name, nickname, phone_number, darkest_secret);
	
}

void	search_contact(PhoneBook &my_phonebook)
{
	std::string input;
	int 		index;
	int			max_index = my_phonebook.get_contact_count();

	if (max_index == 0)
	{
		std::cerr << "There are no contacts in the phonebook" << std::endl;
		return;
	}
	my_phonebook.print_phonebook();
	
	while (true)
	{
		index = get_index();
	
		if (index < max_index && index >= 0)
			break;
		else if (index < 0)
			std::cerr << "Index cannot be negative!" << std::endl;
		else if (max_index == 1)
			std::cerr << "There is only 1 contact in the phonebook" << std::endl;
		else
			std::cerr << "There are only " << max_index << " contacts in the phonebook" << std::endl;
	}
	my_phonebook.print_contact(index);
}

std::string get_data(std::string field)
{
	std::string data;
	int			phone_number;

	while (true)
	{
		std::cout << "Enter " << field << ": ";
		std::getline(std::cin, data);
		data = trim(data);
		if (data.length() == 0)
		{
			std::cout << field << " cannot be empty!" << std::endl;
			continue;
		}
		if (field == "Phone Number" && !valid_phone_number(data))
		{
			std::cerr << "Phone number is not valid!" << std::endl;
			continue;
		}
		break;
	}
	return data;
}

int get_index(void)
{
	int 		index;
	std::string input;

	while (true)
	{
		std::cout << "Enter the index of the contact you want to see: ";
		std::getline(std::cin, input);

		try
		{
			index = std::stoi(input);
		}
		catch (std::invalid_argument &e)
		{
			std::cerr << "Index must be a number!" << std::endl;
			continue;
		}
		catch (std::out_of_range &e)
		{
			std::cerr << "Index is out of range!" << std::endl;
			continue;
		}
		break;
	}
	return index;
}

std::string	trim(std::string str)
{
	std::string trimmed = "";

	if (!str.empty())
	{
		std::string::iterator it = str.begin();

		while (it != str.end())
		{
			while (it != str.end() && std::isspace(*it))
				it++;
			while (it != str.end() && !std::isspace(*it))
				trimmed += *it++;
			trimmed += ' ';
		}
		
		while (std::isspace(trimmed.back()))
			trimmed.pop_back();
	}
	return trimmed;
}

bool	valid_phone_number(std::string phone_number)
{
	std::string::iterator it = phone_number.begin();
	
	if (*it == '+')
		it++;
	while (it != phone_number.end())
	{
		if (!std::isdigit(*it) && !std::isspace(*it))
			return false;
		it++;
	}
	if (phone_number == "+")
		return false;
	return true;
}
