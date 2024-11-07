/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:42:33 by cseriildii        #+#    #+#             */
/*   Updated: 2024/11/07 16:50:56 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NOLINTBEGIN(readability-convert-member-functions-to-static, performance-unnecessary-value-param, cppcoreguidelines-pro-bounds-constant-array-index)

#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug( void )
{
	std::cerr << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info( void )
{
	std::cerr << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning( void )
{
	std::cerr << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error( void )
{
	std::cerr << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain( std::string level )
{
	const char *levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void (Harl::*funcPointers[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	int index = OTHER;;
	for (int i = 0; i <= 3; i++)
	{
		if (levels[i] == level)
		{
			index = i;
			break ;
		}
	}

	switch (index)
	{
		case OTHER:
			std::cout << "Unkown level\n";
			return ;
		default:
			(this->*funcPointers[index])();
	}
}

//NOLINTEND(readability-convert-member-functions-to-static, performance-unnecessary-value-param, cppcoreguidelines-pro-bounds-constant-array-index)
