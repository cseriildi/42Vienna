/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:56:34 by icseri            #+#    #+#             */
/*   Updated: 2024/11/09 07:56:21 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	public:
	
		Fixed();
		Fixed(const Fixed& other); // Copy constructor
		~Fixed();
		Fixed& operator=(const Fixed& other); // Copy asssignment 

		int		getRawBits( void ) const;
		void	setRawBits( int const raw ); //NOLINT
		
	private:
		
		int					_value;
		static const int	_nbFractBits = 8;
};

#endif
