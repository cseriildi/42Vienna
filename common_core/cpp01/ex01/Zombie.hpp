/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:14:48 by icseri            #+#    #+#             */
/*   Updated: 2024/09/08 21:44:28 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:

		Zombie();
		~Zombie();

		void 	setName(std::string name);
		void	announce(void);
		
	private:

		std::string		_name;
		
};

Zombie		*zombieHorde(int N, std::string name);
std::string	ft_itoa(int n);
int			ft_atoi(const std::string& num);
bool		is_valid_input(int argc, char **argv);

#endif
