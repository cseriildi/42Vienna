#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap("_clap_name",
							FragTrap::_hp,
							ScavTrap::_ep,
							FragTrap::_ad)
{
	std::cout << "DiamondTrap: Default constructor called\n";
}

DiamondTrap::DiamondTrap(const std::string& name,
						unsigned int hitPoints,
						unsigned int energyPoints,
						unsigned int attackDamage)
	: ClapTrap(name + "_clap_name", hitPoints, energyPoints, attackDamage),
	_name(name)
{
	std::cout << "DiamondTrap: Parameterized constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other._name, other._hitPoints, other._energyPoints, other._attackDamage),
	FragTrap(other),
	ScavTrap(other)
{
	std::cout << "DiamondTrap: Copy constructor called\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Destructor called\n";
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_attackDamage = other._attackDamage;
		_energyPoints = other._energyPoints;
		_hitPoints = other._hitPoints;
	}
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << "\n";
}
