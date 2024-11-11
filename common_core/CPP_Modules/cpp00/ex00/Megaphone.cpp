#include <iostream> // std::cout
#include <string> // std::string
#include <cctype> //std::toupper

std::string make_it_loud(std::string text)
{
	std::string::iterator it; 
	
	for (it = text.begin(); it != text.end(); it++)
		*it = std::toupper(*it); // NOLINT I don't find the casting necessary
	return text;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	
	for (int i = 1; i < argc; i++)
		std::cout << make_it_loud(argv[i]); //NOLINT we can't use vectors, that would be more the c++ way
	
	std::cout << "\n"; // changed from: "std::endl;" it is more efficient to not trigger flush manually
		
    return 0;
}
