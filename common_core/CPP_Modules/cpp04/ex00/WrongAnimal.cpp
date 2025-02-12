#include "WrongAnimal.hpp"
#include "../colors.hpp"
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal() 
{
	std::cout << ITALIC "WrongAnimal: Default constructor called\n" RESET;
}

WrongAnimal::WrongAnimal(const std::string& type): _type(type) 
{
	std::cout << ITALIC "WrongAnimal: Parameterized constructor called\n" RESET;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): _type(other._type)
{
	std::cout << ITALIC "WrongAnimal: Copy constructor called\n" RESET;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << ITALIC "WrongAnimal: Destructor called\n" RESET;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void WrongAnimal::makeSound() const  //NOLINT
{
	std::cout << BLUE "Can't make sound!\n" RESET;
}

const std::string&	WrongAnimal::getType() const {return _type;}
