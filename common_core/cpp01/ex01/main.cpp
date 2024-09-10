/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:35:39 by cseriildii        #+#    #+#             */
/*   Updated: 2024/09/10 10:10:32 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

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
		std::cout << "Usage: " << argv[0] << " <number of zombies to create (range int)> <name>"<< std::endl;
		return false;
	}
	for  (int i = 0; argv[1][i]; i++)
	{
		if (!std::isdigit(argv[1][i]))
		{
			std::cout << "Invalid number of zombies." << std::endl;
			return false;
		}
	}
	if (std::string(argv[1]) != std::string(ft_itoa(ft_atoi(argv[1]))))
	{
		std::cout << "Invalid number of zombies." << std::endl;
		return false;
	}
	if (ft_atoi(argv[1]) < 1)
	{
		std::cout << "Cmon let's create at least 1 zombie" << std::endl;
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
	while (it != num.end() && std::isdigit(*it))
	{
		result = result * 10 + *it - '0';
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
