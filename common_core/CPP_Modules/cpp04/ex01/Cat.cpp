#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

Cat::Cat(): Animal("Cat"), _brain(new Brain)
{
	std::cout << "Cat: Default constructor called\n";
}

Cat::Cat(const Cat& other): Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Cat: Copy constructor called\n";
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat: Destructor called\n";
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		_type = other._type;
		*_brain = *other._brain;
	}
	return *this;
}

void Cat::makeSound() const {std::cout << "Meow\n";}

void Cat::think(const std::string& idea) const {_brain->addIdea(idea);}

void Cat::printBrain() const {std::cout << *_brain;}
