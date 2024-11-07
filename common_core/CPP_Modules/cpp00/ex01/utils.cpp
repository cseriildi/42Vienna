/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:13:39 by cseriildii        #+#    #+#             */
/*   Updated: 2024/11/07 16:03:07 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <cstdio>
#include <iostream>
#include <cctype>

void	add_contact(PhoneBook &myPhoneBook)
{
	std::string firstName = get_data("First Name");
	std::string lastName = get_data("Last Name");
	std::string nickname = get_data("Nickname");
	std::string phoneNumber = get_data("Phone Number");
	std::string darkestSecret = get_data("Darkest Secret");

	myPhoneBook.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	
}

void	search_contact(PhoneBook &myPhoneBook)
{
	int 		index = 0;
	int			max_index = myPhoneBook.getContactCount();

	if (max_index == 0)
	{
		std::cerr << "There are no contacts in the phonebook\n";
		return;
	}
	myPhoneBook.printPhonebook();
	
	while (true)
	{
		index = get_index();
	
		if (index < max_index && index >= 0)
			break;
		if (index < 0)
			std::cerr << "Index cannot be negative!\n";
		else if (max_index == 1)
			std::cerr << "There is only 1 contact in the phonebook\n";
		else
			std::cerr << "There are only " << max_index << " contacts in the phonebook\n";
	}
	myPhoneBook.printContact(index);
}

void	reopen_stdin()
{
	if (std::cin.eof())
	{
		std::cin.clear();
		std::cin.ignore(0, '\n');
		std::freopen("/dev/tty", "r", stdin);
		std::cout << "\n";
	}
}


std::string get_data(const std::string& field)
{
	std::string data;

	while (true)
	{
		std::cout << "Enter " << field << ": ";
		std::getline(std::cin, data);
		data = trim(data);
		if (data.empty())
		{
			reopen_stdin();
			std::cerr << field << " cannot be empty!\n";
			continue;
		}
		if (field == "Phone Number" && !valid_phone_number(data))
		{
			std::cerr << "Phone number is not valid!\n";
			continue;
		}
		break;
	}
	return data;
}

int get_index(void)
{
	int 		index = 0;
	std::string input;
	std::string index_str;
	

	while (true)
	{
		std::cout << "Enter the index of the contact you want to see: ";
		std::getline(std::cin, input);

		if (input.empty())
		{
			reopen_stdin();
			std::cerr << "Index cannot be empty!\n";
			continue;
		}
		index = ft_atoi(input);
		index_str = ft_itoa(index);
		if (input != index_str)
		{
			std::cerr << "Index must be a number between 0-7!\n";
			continue;
		}
		break;
	}
	return index;
}

std::string	trim(const std::string& str)
{
	std::string trimmed;

	if (!str.empty())
	{
		std::string::const_iterator it = str.begin();

		while (it != str.end())
		{
			while (it != str.end() && std::isspace(*it) != 0)
				it++;
			while (it != str.end() && std::isspace(*it) == 0)
				trimmed += *it++;
			trimmed += ' ';
		}
		
		while (!trimmed.empty() && std::isspace(*(trimmed.end() - 1)) != 0)
			trimmed.erase(trimmed.length() - 1);
	}
	return trimmed;
}

bool	valid_phone_number(const std::string& phoneNumber)
{
	std::string::const_iterator it = phoneNumber.begin();
	
	if (*it == '+')
		it++;
	while (it != phoneNumber.end())
	{
		if (std::isdigit(*it) == 0 && std::isspace(*it) == 0)
			return false;
		it++;
	}
	return (phoneNumber != "+");
}

int	ft_atoi(const std::string& num)
{
	int result = 0;
	int sign = 1;
	std::string::const_iterator it = num.begin();

	if (*it == '-' || *it == '+')
	{
		if (*it == '-')
			sign = -1;
		it++;
	}
	while (it != num.end() && std::isdigit(*it) != 0)
	{
		result = result * 10 + *it - '0'; //NOLINT
		it++;
	}
	return result * sign;
}
