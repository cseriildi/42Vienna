//NOLINTBEGIN(readability-convert-member-functions-to-static, cppcoreguidelines-pro-bounds-constant-array-index, bugprone-switch-missing-default-case, performance-unnecessary-value-param)

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
	const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int index = 0;
	while (index < 4 && levels[index] != level)
		index++;

	switch (index)
	{
		case OTHER:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			return ;
		case DEBUG:
			std::cout << "[ DEBUG ]\n";
			debug();
			std::cout << "\n";
		case INFO:
			std::cout << "[ INFO ]\n";
			info();
			std::cout << "\n";
		case WARNING:
			std::cout << "[ WARNING ]\n";
			warning();
			std::cout << "\n";
		case ERROR:
			std::cout << "[ ERROR ]\n";
			error();
			std::cout << "\n";
    }
}

//NOLINTEND(readability-convert-member-functions-to-static, cppcoreguidelines-pro-bounds-constant-array-index, bugprone-switch-missing-default-case, performance-unnecessary-value-param)

