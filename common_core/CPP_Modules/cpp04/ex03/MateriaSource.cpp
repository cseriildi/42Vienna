//NOLINTBEGIN(cppcoreguidelines-pro-bounds-constant-array-index)

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <cstddef>
#include <string>
#include <iostream>

MateriaSource::MateriaSource(): _inventory() {}

MateriaSource::MateriaSource(const MateriaSource& other): _inventory()
{
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i] != NULL)
			_inventory[i] = other._inventory[i]->clone();
	}
}

MateriaSource::~MateriaSource() {}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++) {
			if (other._inventory[i] != NULL)
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
	{
		std::cerr << "Invalid materia\n";
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL) {
			_inventory[i] = m->clone();
			std::cerr << "Materia " << m->getType() << " learned\n";
			return;
		}
	}
	std::cerr << "Inventory is full\n";
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL && _inventory[i]->getType() == type)
		{
			std::cerr << "Materia " << type << " created\n";
			return _inventory[i]->clone();
		}
	}
	std::cerr << "Materia " << type << " is not in inventory!\n";
	return NULL;
}

void MateriaSource::printInventory() const
{
	std::cerr << "\nInventory:\n";
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
