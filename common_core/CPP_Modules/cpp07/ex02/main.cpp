//NOLINTBEGIN(readability-magic-numbers)

#include "Array.hpp"
#include <iostream>

int main(void)
{
	Array<int> arr(5);

	std::cout << arr << "\n";
	std::cout << "Size: " << arr.size() << "\n";
}
//NOLINTEND(readability-magic-numbers)
