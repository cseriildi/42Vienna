/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:35:39 by cseriildii        #+#    #+#             */
/*   Updated: 2024/09/06 16:03:30 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int		main(void)
{
	PhoneBook 	my_phonebook;
	std::string input;
	
	while (true)
	{
		std::cout << "Enter a command (ADD/SEARCH/EXIT): ";
		std::getline(std::cin, input);
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			add_contact(my_phonebook);
		else if (input == "SEARCH")
			search_contact(my_phonebook);
		else
			continue;
	}
	return 0;
}
