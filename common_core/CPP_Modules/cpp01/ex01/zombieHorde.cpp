#include "Zombie.hpp"
#include <string>

Zombie	*zombieHorde(int N, std::string name) //NOLINT
{	
	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(name); //NOLINT
		//TEST
		//zombies[i].setName(name + "_" + ft_itoa(i));
	}
		
	return zombies;
}
