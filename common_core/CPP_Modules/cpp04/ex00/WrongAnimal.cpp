#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal() 
{
	std::cout << "WrongAnimal: Default constructor called\n";
}

WrongAnimal::WrongAnimal(const std::string& type): _type(type) 
{
	std::cout << "WrongAnimal: Parameterized constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): _type(other._type)
{
	std::cout << "WrongAnimal: Copy constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor called\n";
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
	std::cout << "I can't talk\n";
}

const std::string&	WrongAnimal::getType() const {return _type;}
