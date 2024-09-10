/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:15:42 by icseri            #+#    #+#             */
/*   Updated: 2024/09/10 12:55:06 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon &weapon)
	: _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}


void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
