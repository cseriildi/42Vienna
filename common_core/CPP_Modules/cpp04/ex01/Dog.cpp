#include "Dog.hpp"
#include "Animal.hpp"
#include <string>
#include <iostream>

Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog: Default constructor called\n";
}

Dog::Dog(const Dog& other): Animal(other)
{
	std::cout << "Dog: Copy constructor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called\n";
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof\n";
}
