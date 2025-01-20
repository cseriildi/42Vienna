#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal
{
	public:

		Cat();
		Cat(const Cat& other);
		~Cat();
		Cat&	operator=(const Cat& other);

		void makeSound() const;
		void printBrain() const;
		void think(const std::string& idea) const;

	private:
		Brain *_brain;
};

#endif
