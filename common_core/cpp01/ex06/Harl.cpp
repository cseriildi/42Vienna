/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:42:33 by cseriildii        #+#    #+#             */
/*   Updated: 2024/11/05 14:53:59 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug( void )
{
	std::cerr << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cerr << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cerr << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cerr << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	const char *levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

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
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			return ;
		case DEBUG:
			std::cout << "[ DEBUG ]" << std::endl;
			this->debug();
			std::cout << std::endl;
		case INFO:
			std::cout << "[ INFO ]" << std::endl;
			this->info();
			std::cout << std::endl;
		case WARNING:
			std::cout << "[ WARNING ]" << std::endl;
			this->warning();
			std::cout << std::endl;
		case ERROR:
			std::cout << "[ ERROR ]" << std::endl;
			this->error();
			std::cout << std::endl;
    }
}
