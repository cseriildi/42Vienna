//NOLINTBEGIN(cppcoreguidelines-pro-bounds-constant-array-index)

#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "../colors.hpp"
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

void Character::setName(const std::string& name) {_name = name;}

void Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cerr << RED "Invalid materia\n" RESET;
		return;
	}
	if (m->isEquipped())
	{
		std::cerr << RED "Materia is already equipped\n" RESET;
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
	std::cerr << RED "Inventory is full\n" RESET;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cerr << RED "Invalid index\n" RESET;
		return;
	}
	if (_inventory[idx] == NULL)
	{
		std::cerr << RED "No materia equipped at this index\n" RESET;
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
		std::cerr << RED "Invalid index\n" RESET;
		return;
	}
	if (_inventory[idx] == NULL)
	{
		std::cerr << RED "No materia equipped at this index\n" RESET;
		return;
	}
	_inventory[idx]->use(target);
}

void Character::printInventory() const
{
	std::cerr << PURPLE BOLD "\nInventory of " << _name << "\n" NOT_BOLD;
	for (int i = 0; i < 4; i++)
	{
		std::cerr << i << ": ";
		if (_inventory[i] != NULL)
			std::cerr << _inventory[i]->getType();
		std::cerr << "\n";
	}
	std::cerr << RESET "\n";
}

//NOLINTEND(cppcoreguidelines-pro-bounds-constant-array-index)
