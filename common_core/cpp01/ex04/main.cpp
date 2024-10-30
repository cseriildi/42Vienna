/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:40:34 by icseri            #+#    #+#             */
/*   Updated: 2024/10/30 14:23:07 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string	replace(std::string text, std::string s1, std::string s2)
{
	std::string	new_text = "";
	std::string	chunk = "";
	std::size_t	index = 0;
	std::size_t len = text.length();

	while (index < len)
	{
		std::size_t position = text.substr(index, len).find(s1);
		if (position == std::string::npos)
		{
			new_text.append(text.substr(index, len - index));
			return new_text;
		}
		chunk = text.substr(index, position);
		index += chunk.length() + s1.length();
		new_text.append(chunk);
		new_text.append(s2);
	}

	return new_text;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << argv[0] << " <filename> <string to replace> <string to replace with>" << std::endl;
		return 1;
	}

	std::string	infile = std::string(argv[1]);
	std::string outfile = infile + ".replace";
	
	std::ifstream inFile(infile.c_str(), std::ios::in);
	if (!inFile)
	{
		std::cerr << " Couldn't open " << infile << std::endl;
		return 1;
	}
	
	std::string text;
	getline(inFile, text); 

	std::string line;
	
	while (getline(inFile, line))
		text += "\n" + line;
		
	inFile.close();
	std::string to_replace = argv[2];
	std::string	to_replace_with = argv[3];
	
	std::ofstream outFile(outfile.c_str(), std::ios::out);
	if (!outFile)
	{
		std::cerr << " Couldn't open " << outfile << std::endl;
		return 1;
	}

	outFile << replace(text, to_replace, to_replace_with) << std::flush;
	outFile.close();

	return 0;
}