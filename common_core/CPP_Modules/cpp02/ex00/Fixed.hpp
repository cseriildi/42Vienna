/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:56:34 by icseri            #+#    #+#             */
/*   Updated: 2024/11/08 14:12:55 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other); // Copy constructor
		Fixed& operator=(const Fixed& other); // Copy asssignment 
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw ); //NOLINT
		
	private:
		
		int					_value;
		static const int	_nbFractBits = 8;
};

#endif
