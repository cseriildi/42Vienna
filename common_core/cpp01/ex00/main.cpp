/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:35:39 by cseriildii        #+#    #+#             */
/*   Updated: 2024/09/08 20:33:12 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int		main(void)
{
	Zombie	*zombie = newZombie("Foo");
	zombie->announce();
	delete zombie;
	
	randomChump("Bar");
	
	return 0;
}