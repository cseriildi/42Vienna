#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#include <string>

class AMateria;

class Character: public ICharacter
{
	public:

		Character(const std::string& name);
		Character(const Character& other); 
		Character&	operator=(const Character& other);
		Character&	operator=(const ICharacter& other);
		~Character();

		const std::string& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		void printInventory() const;
		void setName(const std::string& name);

	private:

		Character();

		std::string _name;
		AMateria*	_inventory[4];

};


#endif
