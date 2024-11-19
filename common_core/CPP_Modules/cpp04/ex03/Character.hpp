#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "AMateria.hpp"


class Character
{
	public:

		class ICharacter
		{
			public:
				virtual ~ICharacter() {}
				virtual std::string const & getName() const = 0;
				virtual void equip(AMateria* m) = 0;
				virtual void unequip(int idx) = 0;
				virtual void use(int idx, ICharacter& target) = 0;
		};
	

};


#endif
