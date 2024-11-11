#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(const std::string& name) : _name(name) {}

Zombie::~Zombie()
{
	std::cout << this->_name << " has been destroyed.\n";
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
