/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:14:48 by icseri            #+#    #+#             */
/*   Updated: 2024/11/07 16:28:10 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:

		Zombie();
		~Zombie();

		void 	setName(const std::string& name);
		void	announce(void) const;
		
	private:

		std::string		_name;
		
};

Zombie				*zombieHorde(int N, std::string name);
std::string			ft_itoa(int n);
int					ft_atoi(const std::string& num);
bool				is_valid_input(int argc, char **argv);

#endif
