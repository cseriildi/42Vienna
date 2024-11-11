#include "Zombie.hpp"
#include <string>

void	randomChump(std::string name) //NOLINT
{
	Zombie zombie(name);
	
	zombie.announce();
}
