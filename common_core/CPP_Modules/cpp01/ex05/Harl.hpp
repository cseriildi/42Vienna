/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:19:33 by cseriildii        #+#    #+#             */
/*   Updated: 2024/11/07 16:51:08 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

enum Levels
{
    DEBUG,
	INFO,
	WARNING,
    ERROR,
	OTHER
};

class	Harl
{
	public:

		Harl();
		~Harl();
	
		void complain( std::string level );

	private:

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif
