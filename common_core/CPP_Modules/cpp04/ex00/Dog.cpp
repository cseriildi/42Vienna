#include "Dog.hpp"
#include "Animal.hpp"
#include "../colors.hpp"
#include <string>
#include <iostream>

Dog::Dog(): Animal("Dog")
{
	std::cout << ITALIC "Dog: Default constructor called\n" RESET;
}

Dog::Dog(const Dog& other): Animal(other)
{
	std::cout << ITALIC "Dog: Copy constructor called\n" RESET;
}

Dog::~Dog()
{
	std::cout << ITALIC "Dog: Destructor called\n" RESET;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	std::cout << ITALIC "Dog: Copy assignment operator called\n" RESET;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << BLUE "Woof\n" RESET;
}
