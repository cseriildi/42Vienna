#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public AAnimal
{
	public:

		Dog();
		Dog(const Dog& other);
		~Dog();
		Dog&	operator=(const Dog& other);

		void makeSound();
		void printBrain() const;
		void think(const std::string& idea) const;


	private:
		Brain *_brain;
};

#endif
