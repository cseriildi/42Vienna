/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:15:45 by icseri            #+#    #+#             */
/*   Updated: 2024/09/10 13:08:26 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
	public:

		HumanA(const std::string& name, Weapon& weapon);
		~HumanA();
	
		void		attack(void) const;

	private:

		std::string		_name;
		Weapon&			_weapon;
		
};

#endif