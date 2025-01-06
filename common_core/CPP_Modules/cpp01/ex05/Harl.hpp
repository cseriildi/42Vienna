#ifndef HARL_HPP
# define HARL_HPP

#include <string>

enum Levels
{
    DEBUG,
	INFO,
	WARNING,
    ERROR,
	OTHER
};

class	Harl
{
	public:

		Harl();
		~Harl();
	
		void complain( std::string level );

	private:

		void (Harl::*_funcPointers[4])();

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif
