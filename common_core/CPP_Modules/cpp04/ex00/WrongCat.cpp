#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat(): WrongAnimal("Cat")
{
	std::cout << "WrongCat: Default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	std::cout << "WrongCat: Copy constructor called\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called\n";
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void WrongCat::makeSound()
{
	std::cout << "Meow\n";
}
