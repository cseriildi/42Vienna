/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:40:34 by icseri            #+#    #+#             */
/*   Updated: 2024/09/10 15:46:04 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string	replace(std::string text, std::string s1, std::string s2)
{
	std::string	new_text = text;
	(void)s1;
	(void)s2;
	//replacing

	return new_text;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << argv[0] << " <filename> <string to replace> <string to replace with>" << std::endl;
		return 1;
	}

	std::string	infile = std::string(argv[1]);
	std::string outfile = infile + ".replace";
	
	std::ifstream inFile(infile.c_str(), std::ios::in);
	//error handling
	
	std::string text;
	getline(inFile, text);

	std::string line;
	
	while (getline(inFile, line))
		text += "\n" + line;
		
	inFile.close();
	std::string to_replace = argv[2];
	std::string	to_replace_with = argv[3];
	
	std::ofstream outFile(outfile.c_str(), std::ios::out);
	//error handling

	outFile << replace(text, to_replace, to_replace_with) << std::flush;
	outFile.close();

	return 0;
}