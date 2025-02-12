#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "../colors.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat(): WrongAnimal("Cat")
{
	std::cout << ITALIC "WrongCat: Default constructor called\n" RESET;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	std::cout << ITALIC "WrongCat: Copy constructor called\n" RESET;
}

WrongCat::~WrongCat()
{
	std::cout << ITALIC "WrongCat: Destructor called\n" RESET;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void WrongCat::makeSound() const //NOLINT
{
	std::cout << BLUE "Meow\n" RESET;
}
