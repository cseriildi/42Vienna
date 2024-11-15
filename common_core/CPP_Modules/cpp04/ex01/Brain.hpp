#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	public:

		Brain();
		Brain(const Brain& other);
		Brain&	operator=(const Brain& other);
		virtual ~Brain(); 

	protected:

		std::string		_ideas[100];
};

#endif
