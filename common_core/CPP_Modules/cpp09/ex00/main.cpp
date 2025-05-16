//NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic)

#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>


void parseInput(const char *filename)
{
	std::ifstream file(filename);
	if (!file)
		throw std::runtime_error("Could not open file");
		
	std::string line;

	bool header_checked = false;
	while (std::getline(file, line) != 0)
	{
		if (!header_checked){
			header_checked = true;
			if (line == "date | value")
				continue;
		}

		try {
			BitcoinExchange::buy(line);
		} catch (const std::exception &e) {
			std::cout << "Error: " << e.what() << "\n";
		}
	}
	file.close();
}

int main(int argc, char **argv) try {
	if (argc != 2)
	{
		std::cout << "Usage: ./btc <filename>\n";
		return 1;
	}
	
	parseInput(argv[1]);
	return 0;

} catch (const std::exception &e) {
	std::cerr << "Error: " << e.what() << "\n";
	return 1;
} catch (...) {
	std::cerr << "Unknown error\n";
	return 1;
}

//NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic)
