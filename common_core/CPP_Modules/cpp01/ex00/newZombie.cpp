#include "Zombie.hpp"
#include <string>

Zombie	*newZombie(std::string name) //NOLINT
{
	return new Zombie(name);
}
