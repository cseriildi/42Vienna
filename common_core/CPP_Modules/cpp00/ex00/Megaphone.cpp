#include <iostream>
#include <string>
#include <cctype>

std::string make_it_loud(std::string text)
{
	std::string::iterator it; 
	
	for (it = text.begin(); it != text.end(); it++)
		*it = std::toupper(*it); // NOLINT
	return text;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	
	for (int i = 1; i < argc; i++)
		std::cout << make_it_loud(argv[i]); //NOLINT
	
	std::cout << "\n";
		
    return 0;
}
