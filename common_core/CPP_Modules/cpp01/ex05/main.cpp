/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:40:34 by icseri            #+#    #+#             */
/*   Updated: 2024/11/05 15:01:56 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int	main()
{
	Harl myHarl;

	myHarl.complain("DEBUG");
	myHarl.complain("INFO");
	myHarl.complain("WARNING");
	myHarl.complain("ERROR");
	myHarl.complain("whatever");
	
	return 0;
}
