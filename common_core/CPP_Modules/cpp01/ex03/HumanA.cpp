#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(const std::string& name, Weapon &weapon)
	: _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << "\n";
}
