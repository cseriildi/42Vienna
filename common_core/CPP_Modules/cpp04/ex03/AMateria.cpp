#include "AMateria.hpp"
#include <string>

AMateria::AMateria() {}

AMateria::AMateria(const std::string& type): _type(type) {}

AMateria::AMateria(const AMateria& other): _type(other._type) {}

AMateria::~AMateria() {}

AMateria&	AMateria::operator=(const AMateria& other)
{
	//While assigning a Materia to another, copying the type doesn’t make sense.
	(void)other;
	return *this;
}

const std::string&	AMateria::getType() const {return _type;}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	//not sure what to do here
}
