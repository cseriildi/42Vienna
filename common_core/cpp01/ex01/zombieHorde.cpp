/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:42:11 by cseriildii        #+#    #+#             */
/*   Updated: 2024/09/10 11:23:59 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, const std::string& name)
{	
	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
		//TEST
		//zombies[i].setName(name + "_" + ft_itoa(i));
	}
		
	return zombies;
}
