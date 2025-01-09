#include "Fixed.hpp"
#include <iostream>

//NOLINTBEGIN

int main( void ) {
	{
		std::cout << "Tests from subject:\n";

		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		std::cout << "\nMy tests:\n";

		Fixed a = Fixed(8388607.5f);
		std::cout << "a: " << a << "\n";
		a++;
		std::cout << "a after a++: " << a << "\n";
		Fixed b = Fixed(-8388608);
		std::cout << "b: " << b << "\n";
		b--;
		std::cout << "b after b--: " << b << "\n";

		a = 100;
		b = 50;
		std::cout << "a: " << a << " b: " << b << "\n";
		std::cout << "a + b: " << a + b << "\n";
		std::cout << "a - b: " << a - b << "\n";
		std::cout << "a * b: " << a * b << "\n";
		std::cout << "a / b: " << a / b << "\n";
		std::cout << "a > b: " << (a > b ?  "true" : "false") << "\n";
		std::cout << "a >= b: " << (a >= b ?  "true" : "false") << "\n";
		std::cout << "a < b: " << (a < b ?  "true" : "false") << "\n";
		std::cout << "a <= b: " << (a <= b ?  "true" : "false") << "\n";
		std::cout << "a == b: " << (a == b ?  "true" : "false") << "\n";
		std::cout << "a != b: " << (a != b ?  "true" : "false") << "\n";
		std::cout << "min(a, b): " << Fixed::min(a, b) << "\n";
		std::cout << "max(a, b): " << Fixed::max(a, b) << "\n";
	}
}

//NOLINTEND
