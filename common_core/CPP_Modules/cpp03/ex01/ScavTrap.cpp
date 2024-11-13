#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap("", 100, 50, 20)
{
	std::cout << "ScavTrap: Default constructor called\n";
}

ScavTrap::ScavTrap(const std::string& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage): ClapTrap(name, hitPoints, energyPoints, attackDamage)
{
	std::cout << "ScavTrap: Parameterized constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other._name, other._hitPoints, other._energyPoints, other._attackDamage)
{
	std::cout << "ScavTrap: Copy constructor called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor called\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
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

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " has died already and can't attack!\n";
	}
	else if (_energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
	}
	else
		std::cout << "ScavTrap " << _name << " doesn't have enough energy points to attack " << target << "!\n";

}

void ScavTrap::guardGate()
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " has died already and can't switch to gate keeper mode!\n";
	}
	else
		std::cout << "ScavTrap is now in Gate keeper mode.\n";
}
