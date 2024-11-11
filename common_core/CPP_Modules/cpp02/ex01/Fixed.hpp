#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
	
		Fixed();
		Fixed(int num);
		Fixed(float num);
		Fixed(const Fixed& other);
		~Fixed();
		Fixed& operator=(const Fixed& other);

		int		getRawBits( void ) const;
		void	setRawBits( int raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
	private:
		
		int					_value;
		static const int	_nbFractBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& other);

#endif
