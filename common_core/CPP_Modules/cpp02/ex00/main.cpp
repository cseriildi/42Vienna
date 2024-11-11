#include "Fixed.hpp"
#include <iostream>

//NOLINTBEGIN

int main( void ) {
	
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b; //This is almost the same as c.operator=(b);
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return 0;
}

//NOLINTEND

