#include <iostream>
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN < inverted Polish mathematical expression>\n";
		return (1);
	}
	(void)argv;
	int result = 0;
	//TODO: parse argv[1]
		//TODO: numbers in (0-9)
		//TODO: operators: + - * /
		//TODO: put numbers in a std::stack
		//TODO: division by 0: error message

	//TODO: in a while pop an element from the stack and do the operation until the stack is empty
	
	std::cout << "Result: " << result << "\n";

}

