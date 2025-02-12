#include "AAnimal.hpp"
#include "../colors.hpp"
#include <string>
#include <iostream>

AAnimal::AAnimal() 
{
	std::cout << ITALIC "AAnimal: Default constructor called\n" RESET;
}

AAnimal::AAnimal(const std::string& type): _type(type) 
{
	std::cout << ITALIC "AAnimal: Parameterized constructor called\n" RESET;
}

AAnimal::AAnimal(const AAnimal& other): _type(other._type)
{
	std::cout << ITALIC "AAnimal: Copy constructor called\n" RESET;
}

AAnimal::~AAnimal()
{
	std::cout << ITALIC "AAnimal: Destructor called\n" RESET;
}

AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

const std::string&	AAnimal::getType() const {return _type;}
