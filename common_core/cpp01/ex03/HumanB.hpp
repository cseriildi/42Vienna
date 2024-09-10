/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:15:50 by icseri            #+#    #+#             */
/*   Updated: 2024/09/10 13:08:22 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB
{
	public:

		HumanB(const std::string& name);
		~HumanB();

		void	setWeapon(Weapon &weapon);
	
		void	attack(void) const;

	private:

		std::string		_name;
		Weapon			*_weapon;
		
};

#endif
