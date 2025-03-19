#include "ScalarConverter.hpp"
#include <iostream>

void test_chars(void);
void test_ints(void);
void test_floats(void);
void test_doubles(void);

int main(int argc, char **argv)
{
	if (argc != 1)
	{
		for (int i = 1; i != argc; i++)
		{
			if (i >= 2)
				std::cout << "\n";
			ScalarConverter::convert(argv[i]);
		}
	}
	else
	{
		test_chars();
		test_ints();
		test_floats();
		test_doubles();
	}
}

