#include "Fixed.hpp"
#include <iostream>
#include <cmath> 
#include <iomanip>
#include <climits>

Fixed::Fixed(): _value (0) {std::cout << "Default constructor called\n";}

Fixed::Fixed(const int num)
{
	if (num >= INT_MAX / (1 << _nbFractBits))
		_value = INT_MAX;
	else
		_value = num * (1 << _nbFractBits);
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float num)
{
	if (num >= INT_MAX / (1 << _nbFractBits))
		_value = INT_MAX;
	else
		_value = static_cast<int>(roundf(num * (1 << _nbFractBits)));
	std::cout << "Float constructor called\n";
	
}

Fixed::~Fixed() {std::cout << "Destructor called\n";}

//Fixed::Fixed(const Fixed& other): _value(other._value) {std::cout << "Copy constructor called\n";}

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

int Fixed::getFractionalBits(void) const {return _nbFractBits;} //NOLINT

int Fixed::getRawBits( void ) const {return this->_value;}

void Fixed::setRawBits( int const raw ) {this->_value = raw;}

float	Fixed::toFloat( void ) const
{
	return static_cast<float>(this->getRawBits()) / static_cast<float>(1 << _nbFractBits);;
}

int		Fixed::toInt( void ) const
{
	return this->getRawBits() >> _nbFractBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
	return os << std::setprecision(other.getFractionalBits()) << other.toFloat();
}
