/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:40:34 by icseri            #+#    #+#             */
/*   Updated: 2024/10/30 16:22:53 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int	main()
{
	Harl myHarl;

	std::string level;

	level = "DEBUG";
	myHarl.complain(level);
	level = "INFO";
	myHarl.complain(level);
	level = "WARNING";
	myHarl.complain(level);
	level = "ERROR";
	myHarl.complain(level);
	level = "WHATEVER";
	myHarl.complain(level);
	
	
	return 0;
}