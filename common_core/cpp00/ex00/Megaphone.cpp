/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:36:54 by icseri            #+#    #+#             */
/*   Updated: 2024/09/04 15:00:02 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>

std::string	make_it_loud(std::string text)
{
	std::string::iterator it; 
	
	for (it = text.begin(); it != text.end(); it++)
		*it = std::toupper(*it);
	return text;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	
	for (int i = 1; i < argc; i++)
		std::cout << make_it_loud(argv[i]);
	
	std::cout << std::endl;
		
    return 0;
}
