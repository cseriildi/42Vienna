#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
	public:

		Dog();
		Dog(const Dog& other);
		~Dog();
		Dog&	operator=(const Dog& other);

		void makeSound() const;
		void printBrain() const;
		void think(const std::string& idea) const;


	private:
		Brain *_brain;
};

#endif
