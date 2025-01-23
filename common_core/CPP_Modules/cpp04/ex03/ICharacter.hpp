#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class AMateria;

class ICharacter //NOLINT
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
