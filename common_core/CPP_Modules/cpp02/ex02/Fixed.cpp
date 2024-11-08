/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:03:05 by icseri            #+#    #+#             */
/*   Updated: 2024/11/08 18:52:26 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): _value (0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num): _value(num << _nbFractBits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed( float num) : _value(static_cast<int>(num * (1 << _nbFractBits)))
{
	std::cout << "Float constructor called\n";
}


Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

/* 
// I like this one more tbh
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

std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
	return os << other.toFloat();
}

bool Fixed::operator<(const Fixed& other)
{
	return this->toFloat() < other.toFloat();
}

bool Fixed::operator>(const Fixed& other)
{
	return this->toFloat() > other.toFloat();
}

bool Fixed::operator>=(const Fixed& other)
{
	return this->toFloat() >= other.toFloat();

}

bool Fixed::operator<=(const Fixed& other)
{
	return this->toFloat() <= other.toFloat();
}

bool Fixed::operator==(const Fixed& other)
{
	return this->toFloat() == other.toFloat();

}

bool Fixed::operator!=(const Fixed& other)
{
	return this->toFloat() != other.toFloat();
}

/* Fixed& Fixed::operator+(const Fixed& other)
{
	
}

Fixed& Fixed::operator-(const Fixed& other)
{
	
}

Fixed& Fixed::operator*(const Fixed& other)
{
	
}

Fixed& Fixed::operator/(const Fixed& other)
{
	
} */

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return this->_value;
}

void Fixed::setRawBits( int const raw )
{	
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	float as_float = static_cast<float>(this->getRawBits()) / static_cast<float>(1 << _nbFractBits);

	return as_float;
}

int		Fixed::toInt( void ) const
{
	int as_int = this->getRawBits() >> _nbFractBits;

	return as_int;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() <= b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
 	if (a.getRawBits() <= b.getRawBits())
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
 	if (a.getRawBits() >= b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
 	if (a.getRawBits() >= b.getRawBits())
		return a;
	return b;
}
