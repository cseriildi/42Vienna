#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
	Cure();
	Cure(const Cure& other);
	~Cure();
	Cure&	operator=(const Cure& other);
};

#endif
