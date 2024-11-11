#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie() {}

Zombie::~Zombie()
{
	std::cout << this->_name << " has been destroyed.\n";
}

void	Zombie::setName(const std::string& name) {this->_name = name;}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
