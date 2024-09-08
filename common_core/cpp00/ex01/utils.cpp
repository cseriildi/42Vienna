/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:13:39 by cseriildii        #+#    #+#             */
/*   Updated: 2024/09/08 18:15:20 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

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
	std::string input;
	int 		index;
	int			max_index = myPhoneBook.getContactCount();

	if (max_index == 0)
	{
		std::cerr << "There are no contacts in the phonebook" << std::endl;
		return;
	}
	myPhoneBook.printPhonebook();
	
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
	myPhoneBook.printContact(index);
}

std::string get_data(const std::string& field)
{
	std::string data;

	while (true)
	{
		std::cout << "Enter " << field << ": ";
		std::getline(std::cin, data);
		data = trim(data);
		if (data.length() == 0)
		{
			std::cerr << field << " cannot be empty!" << std::endl;
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
	std::string index_str;
	

	while (true)
	{
		std::cout << "Enter the index of the contact you want to see: ";
		std::getline(std::cin, input);

		if (input.length() == 0)
		{
			std::cerr << "Index cannot be empty!" << std::endl;
			continue;
		}
		index = ft_atoi(input);
		index_str = ft_itoa(index);
		if (input != index_str)
		{
			std::cerr << "Index must be a number between 0-7!" << std::endl;
			continue;
		}
		break;
	}
	return index;
}

std::string	trim(const std::string& str)
{
	std::string trimmed = "";

	if (!str.empty())
	{
		std::string::const_iterator it = str.begin();

		while (it != str.end())
		{
			while (it != str.end() && std::isspace(*it))
				it++;
			while (it != str.end() && !std::isspace(*it))
				trimmed += *it++;
			trimmed += ' ';
		}
		
		while (!trimmed.empty() && std::isspace(*(trimmed.end() - 1)))
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
		if (!std::isdigit(*it) && !std::isspace(*it))
			return false;
		it++;
	}
	if (phoneNumber == "+")
		return false;
	return true;
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
	while (it != num.end() && std::isdigit(*it))
	{
		result = result * 10 + *it - '0';
		it++;
	}
	return result * sign;
}
