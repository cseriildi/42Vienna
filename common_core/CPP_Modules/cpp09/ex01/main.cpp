//NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic)

#include "RPN.hpp"
#include <exception>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN <inverted Polish mathematical expression>\n";
		return (1);
	}
	try {
		rpn(argv[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
}

//NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic)
