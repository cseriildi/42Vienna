#include "Cat.hpp"
#include "Animal.hpp"
#include <string>
#include <iostream>

Cat::Cat(): Animal("Cat")
{
	std::cout << "Cat: Default constructor called\n";
}

Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << "Cat: Copy constructor called\n";
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called\n";
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
	std::cout << "Meow\n";
}
