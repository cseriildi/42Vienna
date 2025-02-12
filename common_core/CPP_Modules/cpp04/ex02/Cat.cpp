#include "Cat.hpp"
#include "AAnimal.hpp"
#include "Brain.hpp"
#include "../colors.hpp"
#include <string>
#include <iostream>

Cat::Cat(): AAnimal("Cat"), _brain(new Brain)
{
	std::cout << ITALIC "Cat: Default constructor called\n" RESET;
}

Cat::Cat(const Cat& other): AAnimal(other), _brain(new Brain(*other._brain))
{
	std::cout << ITALIC "Cat: Copy constructor called\n" RESET;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << ITALIC "Cat: Destructor called\n" RESET;
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

void Cat::makeSound() {std::cout << BLUE "Meow\n" RESET;}

void Cat::think(const std::string& idea) const {_brain->addIdea(idea);}

void Cat::printBrain() const {std::cout << *_brain;}
