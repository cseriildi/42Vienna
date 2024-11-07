/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:40:34 by icseri            #+#    #+#             */
/*   Updated: 2024/11/07 16:45:13 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>

std::string	replace(const std::string& text, const std::string& s1, const std::string& s2)
{
	if (s1.empty())
		return text;
	
	std::string	new_text;
	std::size_t	index = 0;
	std::size_t len = text.length();

	while (index < len)
	{
		std::size_t position = text.find(s1, index);
		if (position == std::string::npos)
		{
			new_text.append(text.substr(index));
			break ;
		}
		new_text.append(text, index, position - index);
		new_text.append(s2);
		index = position + s1.length();
	}

	return new_text;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << *argv << " <filename> <string to replace> <string to replace with>\n";
		return 1;
	}

	std::string	infile = std::string(argv[1]); //NOLINT
	std::string outfile = infile + ".replace";
	
	std::ifstream inFile(infile.c_str(), std::ios::in);
	if (!inFile)
	{
		std::cerr << " Couldn't open " << infile << "\n";
		return 1;
	}
	
	std::string text;
	getline(inFile, text); 

	std::string line;
	
	while (getline(inFile, line) != NULL)
		text += "\n" + line;
		
	inFile.close();
	std::string to_replace = argv[2]; // NOLINT
	std::string	to_replace_with = argv[3]; // NOLINT
	
	std::ofstream outFile(outfile.c_str(), std::ios::out);
	if (!outFile)
	{
		std::cerr << " Couldn't open " << outfile << "\n";
		return 1;
	}

	outFile << replace(text, to_replace, to_replace_with) << std::flush;
	outFile.close();

	return 0;
}
