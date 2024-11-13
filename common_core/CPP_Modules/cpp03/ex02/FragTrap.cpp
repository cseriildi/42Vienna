#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(): ClapTrap("", 100, 50, 20)
{
	std::cout << "FragTrap: Default constructor called\n";
}

FragTrap::FragTrap(const std::string& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage): ClapTrap(name, hitPoints, energyPoints, attackDamage)
{
	std::cout << "FragTrap: Parameterized constructor called\n";
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other._name, other._hitPoints, other._energyPoints, other._attackDamage)
{
	std::cout << "FragTrap: Copy constructor called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor called\n";
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
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


void FragTrap::highFivesGuys()
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " has died already and can't request a high five!\n";
	}
	else
		std::cout << "FragTrap is asking for a figh five.\n";
}
