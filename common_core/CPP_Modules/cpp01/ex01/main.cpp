//NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic)

#include "Zombie.hpp"
#include <sstream>
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage: " << argv[0] << " <number of zombies to create (range int)> <name>\n";
		return 1;
	}

	int number_of_zombies = atoi(argv[1]);
	if (*argv[1] == '+')
		(argv[1])++;
	if (number_of_zombies < 1 || std::string(argv[1]) != ft_itoa(number_of_zombies))
	{
		std::cout << "Invalid number of zombies.\n";
		return 1;
	}

	std::string	name = argv[2];
	Zombie	*zombies = zombieHorde(number_of_zombies, name);

	for (int i = 0; i < number_of_zombies; i++)
		zombies[i].announce();

	delete[] zombies;
	
	return 0;
}

std::string	ft_itoa(int n)
{
	std::stringstream ss;
	ss << n;
	return ss.str();
}

//NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic)
