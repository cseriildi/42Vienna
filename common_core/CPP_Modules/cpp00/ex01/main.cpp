/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:35:39 by cseriildii        #+#    #+#             */
/*   Updated: 2024/11/07 14:58:34 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int		main(void)
{
	PhoneBook 	my_phonebook;
	std::string input;
	
	while (true)
	{
		std::cout << "Enter a command (ADD/SEARCH/EXIT): ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			reopen_stdin();
			continue;
		}
		if (input == "EXIT")
			break;
		if (input == "ADD")
			add_contact(my_phonebook);
		else if (input == "SEARCH")
			search_contact(my_phonebook);
		else
			continue;
	}
	return 0;
}
