//NOLINTBEGIN(cppcoreguidelines-pro-bounds-constant-array-index)

#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#include <cstddef>
#include <iostream>

Character::Character(): _inventory() {}

Character::Character(const std::string& name): _name(name), _inventory() {}

Character::Character(const Character& other): _name(other._name), _inventory()
{
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i] != NULL)
		{
			_inventory[i] = other._inventory[i]->clone();
			_inventory[i]->setEquipped(true);
		}
	}
}

Character::~Character() {}

Character&	Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++) {
			
			if (other._inventory[i] != NULL)
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

Character&	Character::operator=(const ICharacter& other)
{
	const Character *tmp = dynamic_cast<const Character*>(&other);
	*this = *tmp;
	return *this;
}

const std::string& Character::getName() const {return _name;}

void Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cerr << "Invalid materia\n";
		return;
	}
	if (m->isEquipped())
	{
		std::cerr << "Materia is already equipped\n";
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			m->setEquipped(true);
			std::cerr << _name << " equipped " << m->getType() << "\n";
			return;
		}
	}
	std::cerr << "Inventory is full\n";
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cerr << "Invalid index\n";
		return;
	}
	if (_inventory[idx] == NULL)
	{
		std::cerr << "No materia equipped at this index\n";
		return;
	}
	_inventory[idx]->setEquipped(false);
	std::cerr << "Materia " << _inventory[idx]->getType() << " unequipped\n";
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cerr << "Invalid index\n";
		return;
	}
	if (_inventory[idx] == NULL)
	{
		std::cerr << "No materia equipped at this index\n";
		return;
	}
	_inventory[idx]->use(target);
}

void Character::printInventory() const
{
	std::cerr << "\nInventory of " << _name << ":\n";
	for (int i = 0; i < 4; i++)
	{
		std::cerr << i << ": ";
		if (_inventory[i] != NULL)
			std::cerr << _inventory[i]->getType();
		std::cerr << "\n";
	}
	std::cerr << "\n";
}

//NOLINTEND(cppcoreguidelines-pro-bounds-constant-array-index)
