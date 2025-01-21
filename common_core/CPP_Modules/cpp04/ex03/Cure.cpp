#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure& other): AMateria(other) {}

Cure::~Cure() {}

Cure&	Cure::operator=(const Cure& other)
{
	//While assigning a Materia to another, copying the type doesn’t make sense.
	(void)other;
	return *this;
}

AMateria* Cure::clone() const {return new Cure();}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}
