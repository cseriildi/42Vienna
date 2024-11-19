#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

Dog::Dog(): Animal("Dog"), _brain(new Brain)
{
	std::cout << "Dog: Default constructor called\n";
}

Dog::Dog(const Dog& other): Animal(other), _brain(other._brain)
{
	std::cout << "Dog: Copy constructor called\n";
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog: Destructor called\n";
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		_type = other._type;
		_brain = other._brain;
	}
	return *this;
}

void Dog::makeSound()
{
	std::cout << "Woof\n";
}
