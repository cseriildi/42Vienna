/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:15:55 by icseri            #+#    #+#             */
/*   Updated: 2024/09/10 14:14:35 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class	Weapon
{
	public:

		Weapon(const std::string& type);
		~Weapon();
	
		void	setType(const std::string& type);
		const std::string&	getType(void) const;

	private:

		std::string		_type;
};

#endif
