#include "Fixed.hpp"
#include <iostream>

//NOLINTBEGIN

int main( void ) {

	{
		std::cout << "Tests from subject:\n";

		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );

		a = Fixed( 1234.4321f );

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	{
		std::cout << "\nMy tests:\n";

		Fixed default_fixed;
		float fixed_max_should_be = 8388607.99609375f;
		Fixed fixed_max = Fixed(fixed_max_should_be);
		Fixed actual_fixed_max = Fixed(8388607.5f);
		Fixed actual_fixed_min = Fixed(-8388608);

		std::cout << "\nDefault constructed Fixed number is " << default_fixed << ".\n\n";
		
		std::cout << "Technically Fixed max would be 8388607.99609375, but that number is rounded up due to the float rounding rules to: ";
		std::cout << fixed_max_should_be << " which makes the Fixed number overflow to: " << fixed_max << ".\n";
		
		std::cout << "So the actual Fixed max we can accurately construct from a float is: ";
		std::cout << actual_fixed_max << " which is stored as " << actual_fixed_max.getRawBits() << ".\n";
		actual_fixed_max.setRawBits(2147483647);
		std::cout << "We can set the raw bits manually to 2147483647 (int max) and when represented as int it will be: ";
		std::cout << actual_fixed_max.toInt() << ".\n";
		std::cout << "But represented as float it will be rounded up to: ";
		std::cout << actual_fixed_max << ".\n\n";

		std::cout << "And Fixed min is: " << actual_fixed_min ;
		std::cout << " which is stored as " << actual_fixed_min.getRawBits() << ".\n\n";
	}
}

//NOLINTEND
