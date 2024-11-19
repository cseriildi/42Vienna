#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "Character.hpp"
#include <string>

class AMateria
{	
	public:

		AMateria(std::string const & type);
		virtual ~AMateria();

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(Character::ICharacter& target);

	protected:

		AMateria();

		std::string const& _type; //NOLINT

};

#endif
