#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include "../colors.hpp"
#include <string>
#include <iostream>

Dog::Dog(): Animal("Dog"), _brain(new Brain)
{
	std::cout << ITALIC "Dog: Default constructor called\n" RESET;
}

Dog::Dog(const Dog& other): Animal(other), _brain(other._brain)
{
	std::cout << ITALIC "Dog: Copy constructor called\n" RESET;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << ITALIC "Dog: Destructor called\n" RESET;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		_type = other._type;
		*_brain = *other._brain;
	}
	return *this;
}

void Dog::makeSound() const {std::cout << BLUE "Woof\n" RESET;}

void Dog::think(const std::string& idea) const {_brain->addIdea(idea);}

void Dog::printBrain() const {std::cout << *_brain;}

