#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public AAnimal
{
	public:

		Cat();
		Cat(const Cat& other);
		~Cat();
		Cat&	operator=(const Cat& other);

		void makeSound();
		void printBrain() const;
		void think(const std::string& idea) const;

	private:
		Brain *_brain;
};

#endif
