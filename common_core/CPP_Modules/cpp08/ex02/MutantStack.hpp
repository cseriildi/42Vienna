#pragma once

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack() : std::stack<T, Container>() {};
		~MutantStack() {};
		MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {};
		MutantStack &operator=(const MutantStack &other)
		{
			if (this != &other)
				this->c = other.c;
			return *this;
		}
		
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;

		iterator begin() { return this->c.begin();}
		iterator end() { return this->c.end();}

};

