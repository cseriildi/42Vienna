#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <climits>

Fixed::Fixed(): _value (0) {}


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

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other): _value(other._value) {} 

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		_value = other._value;
	return *this;
}

//comparison operators:
bool	Fixed::operator<(const Fixed& other) const {return _value < other._value;}

bool	Fixed::operator>(const Fixed& other) const {return _value > other._value;}

bool	Fixed::operator>=(const Fixed& other) const {return !(*this < other);}

bool	Fixed::operator<=(const Fixed& other) const {return  !(*this > other);}

bool	Fixed::operator==(const Fixed& other) const {return _value == other._value;}

bool	Fixed::operator!=(const Fixed& other) const {return !(*this == other);}

//arithmetic operators:
Fixed	Fixed::operator+(const Fixed& other) const {return Fixed(this->toFloat() + other.toFloat());}

Fixed	Fixed::operator-(const Fixed& other) const {return Fixed(this->toFloat() - other.toFloat());}

Fixed	Fixed::operator*(const Fixed& other) const{return Fixed(this->toFloat() * other.toFloat());}

Fixed	Fixed::operator/(const Fixed& other) const {return Fixed(this->toFloat() / other.toFloat());}

//pre-increment:
Fixed&	Fixed::operator++() {
	if (_value != INT_MAX)
		_value++; 
    return *this;
}

//pre-decrement:
Fixed&	Fixed::operator--() {
	if (_value != INT_MIN)
		_value--;
    return *this;
}

//post-increment:
Fixed	Fixed::operator++(int) {
    Fixed temp(*this);
	if (_value != INT_MAX)
		_value++; 
    return temp;
}

//post-decrement:
Fixed	Fixed::operator--(int) {
    Fixed temp(*this);
	if (_value != INT_MIN)
		_value--;
    return temp;
}

int		Fixed::getRawBits( void ) const {return _value;}

void	Fixed::setRawBits( int const raw ) {_value = raw;}

float	Fixed::toFloat( void ) const {return static_cast<float>(_value) / static_cast<float>(1 << _nbFractBits);}

int		Fixed::toInt( void ) const {return _value >> _nbFractBits;}

//min & max:
Fixed&			Fixed::min(Fixed& a, Fixed& b) {return (a < b) ? a : b;}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {return (a < b) ? a : b;}

Fixed&			Fixed::max(Fixed& a, Fixed& b) {return (a > b) ? a : b;}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {return (a > b) ? a : b;}

int Fixed::getFractionalBits(void) const {return _nbFractBits;} //NOLINT

std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
	return os << std::setprecision(other.getFractionalBits()) << other.toFloat();
}
