/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:15:40 by icseri            #+#    #+#             */
/*   Updated: 2024/11/07 16:25:19 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon(const std::string& type) : _type(type) {}

Weapon::~Weapon() {}

void	Weapon::setType(const std::string& type) {this->_type = type;}

const std::string&	Weapon::getType(void) const {return this->_type;}
