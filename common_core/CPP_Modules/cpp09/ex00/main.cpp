//NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic)

#include <fstream>
#include <iostream>
#include <map>
#include <string>

#define DATABASE "data.csv"

typedef std::string Date;
typedef std::string Value;
typedef std::map<Date, Value> BitcoinExchange;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc <filename>\n";
		return 1;
	}
	//TODO: move this to a function
	std::ifstream csv(DATABASE);
	if (!csv)
	{
		std::cout << "Error: Could not open " DATABASE "\n";
		return 1;
	}
	BitcoinExchange data;
	std::string line;
	while (std::getline(csv, line) != 0)
	{
		//TODO: read it into the map
	}
	
	
	
	std::ifstream file(argv[1]);
	if (!file)
	{
		std::cout << "Error: Could not open file " << argv[1] << "\n";
		return 1;
	}
	while (std::getline(file, line) != 0)
	{
		//TODO: parse line, check date format and value (<= 1000)
		//TODO: use std::lower_bound() to find the corresponding value in map
		//TODO: print the date and value or error message
	}
	file.close();
}


//NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic)
