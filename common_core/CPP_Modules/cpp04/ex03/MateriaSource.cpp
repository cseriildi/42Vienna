//NOLINTBEGIN(cppcoreguidelines-pro-bounds-constant-array-index)

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <cstddef>
#include <string>

MateriaSource::MateriaSource(): _inventory() {}

MateriaSource::MateriaSource(const MateriaSource& other): _inventory()
{
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
		_inventory[i] = other._inventory[i];
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++) {
			if (_inventory[i] != NULL)
				delete _inventory[i];
			_inventory[i] = other._inventory[i];
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL && _inventory[i]->getType() == type)
			return _inventory[i]->clone();
	}
	return NULL;
}

//NOLINTEND(cppcoreguidelines-pro-bounds-constant-array-index)
