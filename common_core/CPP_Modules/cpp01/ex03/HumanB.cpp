/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:15:47 by icseri            #+#    #+#             */
/*   Updated: 2024/11/07 16:24:06 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>
#include <cstddef>

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon &weapon) {this->_weapon = &weapon;}

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with their " << std::flush;
	if (_weapon != NULL)
		std::cout << this->_weapon->getType() << "\n";
	else
		std::cout << "hands" << "\n";
}
