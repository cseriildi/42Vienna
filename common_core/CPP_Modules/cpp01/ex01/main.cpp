//NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic)

#include "Zombie.hpp"
#include <sstream>
#include <iostream>
#include <string>
#include <cctype>

int		main(int argc, char **argv)
{
	if (!is_valid_input(argc, argv))
		return 1;

	Zombie	*zombies = zombieHorde(ft_atoi(argv[1]), argv[2]);
	for (int i = 0; i < ft_atoi(argv[1]); i++)
		zombies[i].announce();

	delete[] zombies;
	
	return 0;
}

bool	is_valid_input(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage: " << argv[0] << " <number of zombies to create (range int)> <name>\n";
		return false;
	}
	for  (int i = 0; argv[1][i] != '\0'; i++)
	{
		if (std::isdigit(argv[1][i]) == 0)
		{
			std::cout << "Invalid number of zombies.\n";
			return false;
		}
	}
	if (std::string(argv[1]) != std::string(ft_itoa(ft_atoi(argv[1]))))
	{
		std::cout << "Invalid number of zombies.\n";
		return false;
	}
	if (ft_atoi(argv[1]) < 1)
	{
		std::cout << "Cmon let's create at least 1 zombie\n";
		return false;
	}
	return true;
}

int	ft_atoi(const std::string& num)
{
	int result = 0;
	int sign = 1;
	std::string::const_iterator it = num.begin();

	if (*it == '-' || *it == '+')
	{
		if (*it == '-')
			sign = -1;
		it++;
	}
	while (it != num.end() && std::isdigit(*it) != 0)
	{
		result = result * 10 + *it - '0'; //NOLINT
		it++;
	}
	return result * sign;
}

std::string	ft_itoa(int n)
{
	std::stringstream ss;
	ss << n;
	return ss.str();
}

//NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic)
