//NOLINTBEGIN(cppcoreguidelines-pro-bounds-constant-array-index)

#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#include <cstddef>

Character::Character(): _inventory() {}

Character::Character(const std::string& name): _name(name), _inventory() {}

Character::Character(const Character& other): _name(other._name), _inventory()
{
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
		_inventory[i] = other._inventory[i];
	}
}

Character::~Character() {}

Character&	Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (_inventory[i] != NULL)
				delete _inventory[i];
			_inventory[i] = other._inventory[i];
		}
	}
	return *this;
}

const std::string& Character::getName() const {return _name;}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4){
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL){
		_inventory[idx]->use(target);
	}
}

//NOLINTEND(cppcoreguidelines-pro-bounds-constant-array-index)
