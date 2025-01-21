#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice& other): AMateria(other) {}

Ice::~Ice() {}

Ice&	Ice::operator=(const Ice& other)
{
	//While assigning a Materia to another, copying the type doesn’t make sense.
	(void)other;
	return *this;
}

AMateria* Ice::clone() const {return new Ice();}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
