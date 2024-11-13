#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap: Default constructor called\n";
}

DiamondTrap::DiamondTrap(const std::string& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage): ClapTrap(name, hitPoints, energyPoints, attackDamage)
{
	std::cout << "DiamondTrap: Parameterized constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other._name, other._hitPoints, other._energyPoints, other._attackDamage)
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

void	DiamondTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "DiamondTrap " << _name << " has died already and can't attack!\n";
	}
	else if (_energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "DiamondTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
	}
	else
		std::cout << "DiamondTrap " << _name << " doesn't have enough energy points to attack " << target << "!\n";

}

void DiamondTrap::guardGate()
{
	if (_hitPoints == 0)
	{
		std::cout << "DiamondTrap " << _name << " has died already and can't switch to gate keeper mode!\n";
	}
	else
		std::cout << "DiamondTrap is now in Gate keeper mode.\n";
}
