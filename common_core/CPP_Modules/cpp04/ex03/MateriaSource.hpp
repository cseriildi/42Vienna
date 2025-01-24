#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#include <string>

class AMateria;

class MateriaSource: public IMateriaSource
{
	public:

		MateriaSource();
		MateriaSource(const MateriaSource& other); 
		MateriaSource&	operator=(const MateriaSource& other);
		virtual ~MateriaSource();

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);

		void printInventory() const;


	private:

		AMateria*	_inventory[4];
};

#endif
