#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): _value (0)
{
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

/* 
Fixed::Fixed(const Fixed& other): _value(other._value)
{
	std::cout << "Copy constructor called\n";
} 
*/

Fixed::Fixed(const Fixed& other) //NOLINT
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return this->_value;
}

void Fixed::setRawBits( int const raw )
{	
	this->_value = raw;
}
