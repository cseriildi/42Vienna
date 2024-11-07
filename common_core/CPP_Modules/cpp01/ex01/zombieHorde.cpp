/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:42:11 by cseriildii        #+#    #+#             */
/*   Updated: 2024/11/07 16:28:36 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
