//NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers, bugprone-easily-swappable-parameters)

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap: Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage): _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
{
	std::cout << "ClapTrap: Parameterized constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other): _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap: Copy constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor called\n";
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
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

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has died already and can't attack!\n";
	}
	else if (_energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
	}
	else
		std::cout << "ClapTrap " << _name << " doesn't have enough energy points to attack " << target << "!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > amount)
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " has been attacked with "<< amount << " points of damage!\n";
	}
	else if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!\n";
	}
	else
	{
	 	_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " has been attacked with "<< amount << " points of damage and died!\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " died and can't be healed!\n";
	}
	else if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " doesn't have enough energy points to heal!\n";
	}
	else
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " healed "<< amount << " points!\n";
	}
}

void	ClapTrap::printInfo()
{
	std::cout << "\nName: " << _name << "\n"
			<< "Hit points: " << _hitPoints << "\n"
			<< "Energy points: " << _energyPoints << "\n"
			<< "Attack damage: " << _attackDamage << "\n\n";
}

//NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers, bugprone-easily-swappable-parameters)
