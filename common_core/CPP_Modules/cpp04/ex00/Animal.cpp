#include "Animal.hpp"
#include "../colors.hpp"
#include <string>
#include <iostream>

Animal::Animal() : _type("Not specified")
{
	std::cout << ITALIC "Animal: Default constructor called\n" RESET;
}

Animal::Animal(const std::string& type): _type(type) 
{
	std::cout << ITALIC "Animal: Parameterized constructor called\n" RESET;
}

Animal::Animal(const Animal& other): _type(other._type)
{
	std::cout << ITALIC "Animal: Copy constructor called\n" RESET;
}

Animal::~Animal()
{
	std::cout << ITALIC "Animal: Destructor called\n" RESET;
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	std::cout << ITALIC "Animal: Copy assignment operator called\n" RESET;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << BLUE "Can't make sound!\n" RESET;
}


const std::string&	Animal::getType() const {return _type;}
