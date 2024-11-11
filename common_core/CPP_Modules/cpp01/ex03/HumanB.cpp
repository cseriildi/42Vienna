#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>
#include <cstddef>

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon &weapon) {this->_weapon = &weapon;}

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with their " << std::flush;
	if (_weapon != NULL)
		std::cout << this->_weapon->getType() << "\n";
	else
		std::cout << "hands" << "\n";
}
