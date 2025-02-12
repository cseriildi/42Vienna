#include "Cat.hpp"
#include "Animal.hpp"
#include "../colors.hpp"
#include <string>
#include <iostream>

Cat::Cat(): Animal("Cat")
{
	std::cout << ITALIC "Cat: Default constructor called\n" RESET;
}

Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << ITALIC "Cat: Copy constructor called\n" RESET;
}

Cat::~Cat()
{
	std::cout << ITALIC "Cat: Destructor called\n" RESET;
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << BLUE "Meow\n" RESET;
}
