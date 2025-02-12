//NOLINTBEGIN(cppcoreguidelines-pro-bounds-constant-array-index, cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

#include "Brain.hpp"
#include "../colors.hpp"
#include <string>
#include <iostream>

Brain::Brain(): _ideaCount(0)
{
	std::cout << ITALIC "Brain: Default constructor called\n" RESET;
}

Brain::Brain(const Brain& other): _ideaCount(other._ideaCount)
{
	std::cout << ITALIC "Brain: Copy constructor called\n" RESET;
	for (int i = 0; i < 100; ++i)
		_ideas[i] = other._ideas[i];
}

Brain::~Brain()
{
	std::cout << ITALIC "Brain: Destructor called\n" RESET;
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			_ideas[i] = other._ideas[i];
		_ideaCount = other._ideaCount;
	}
	return *this;
}

void Brain::addIdea(const std::string& idea)
{
	if (_ideaCount < 100)
	{
		_ideas[_ideaCount++] = idea;
	}
}

const std::string& Brain::getIdea(unsigned int index) const
{
	if (index < 100) {
		return _ideas[index];
	}
	return _ideas[0];
}

unsigned int Brain::getIdeaCount() const {return _ideaCount;}

std::ostream& operator<<(std::ostream& os, const Brain& other)
{
	os << PURPLE;
	for (unsigned int i = 0; i < other.getIdeaCount(); ++i) {
		os << other.getIdea(i) << "\n";
	}
	os << "\n" RESET;
	return os;
}

//NOLINTEND(cppcoreguidelines-pro-bounds-constant-array-index, cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
