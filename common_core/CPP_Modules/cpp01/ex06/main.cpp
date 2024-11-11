#include "Harl.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <level>\n";
		return 1;
	}
	
    Harl myHarl;

	myHarl.complain(argv[1]);

	return 0;
}
