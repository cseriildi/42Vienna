#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	public:

		Brain();
		Brain(const Brain& other);
		Brain&	operator=(const Brain& other);
		virtual ~Brain();

		const std::string& getIdea(unsigned int index) const;
		unsigned int getIdeaCount() const;
		void addIdea(const std::string& idea);
		
	protected:

		std::string		_ideas[100]; //NOLINT
		unsigned int	_ideaCount; //NOLINT
};

std::ostream& operator<<(std::ostream& os, const Brain& other);

#endif
