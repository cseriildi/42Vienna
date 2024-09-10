/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:36:54 by icseri            #+#    #+#             */
/*   Updated: 2024/09/10 10:09:15 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>

std::string	make_it_loud(const std::string& text)
{
	std::string uppercased = text;
	std::string::iterator it; 
	
	for (it = uppercased.begin(); it != uppercased.end(); it++)
		*it = std::toupper(*it);
	return uppercased;
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
