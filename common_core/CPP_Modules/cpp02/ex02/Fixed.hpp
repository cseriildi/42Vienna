/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:56:34 by icseri            #+#    #+#             */
/*   Updated: 2024/11/08 18:53:05 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(int num);
		Fixed(float num);
		Fixed& operator=(const Fixed& other);
		
		bool operator<(const Fixed& other);
		bool operator>(const Fixed& other);
		bool operator>=(const Fixed& other);
		bool operator<=(const Fixed& other);
		bool operator==(const Fixed& other);
		bool operator!=(const Fixed& other);
/* 		Fixed& operator+(const Fixed& other);
		Fixed& operator-(const Fixed& other);
		Fixed& operator*(const Fixed& other);
		Fixed& operator/(const Fixed& other); */
		
		Fixed(const Fixed& other);
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);

		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		
	private:
		
		int					_value;
		static const int	_nbFractBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& other);
#endif
