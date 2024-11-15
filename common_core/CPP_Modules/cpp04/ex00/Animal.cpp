#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal() 
{
	std::cout << "Animal: Default constructor called\n";
}

Animal::Animal(const std::string& type): _type(type) 
{
	std::cout << "Animal: Parameterized constructor called\n";
}

Animal::Animal(const Animal& other): _type(other._type)
{
	std::cout << "Animal: Copy constructor called\n";
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor called\n";
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "I can't talk\n";
}


const std::string&	Animal::getType() const {return _type;}
