/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:53:10 by cseriildii        #+#    #+#             */
/*   Updated: 2024/11/07 16:22:26 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int		main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Memory address of string: " << &string << "\n";
	std::cout << "Memory address held by stringPTR: " << stringPTR << "\n";
	std::cout << "Memory address held by stringREF: " << &stringREF << "\n";

	std::cout << "Value of string: " << string << "\n";
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << "\n";
	std::cout << "Value pointed to by stringREF: " << stringREF << "\n";

	return 0;
}
