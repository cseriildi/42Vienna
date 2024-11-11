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
