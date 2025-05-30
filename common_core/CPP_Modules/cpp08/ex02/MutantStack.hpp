#pragma once

#include <deque>
#include <ostream>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack() : std::stack<T, Container>() {};
		explicit MutantStack(const Container &cont) : std::stack<T, Container>(cont) {};
		~MutantStack() {};
		MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {};
		MutantStack &operator=(const MutantStack &other)
		{
			if (this != &other)
				this->c = other.c;
			return *this;
		}

		typedef typename Container::iterator				iterator;
		typedef typename Container::const_iterator			const_iterator;
		typedef typename Container::reverse_iterator		reverse_iterator;
		typedef typename Container::const_reverse_iterator	const_reverse_iterator;

		iterator begin() {return this->c.begin();}
		const_iterator begin() const {return this->c.begin();}

		iterator end() { return this->c.end();}
		const_iterator end() const { return this->c.end();}

		reverse_iterator rbegin() {return this->c.rbegin();}
		const_reverse_iterator rbegin() const {return this->c.rbegin();}

		reverse_iterator rend() {return this->c.rend();}
		const_reverse_iterator rend() const {return this->c.rend();}

};

template <typename T, typename Container>
std::ostream &operator<<(std::ostream &os, const MutantStack<T, Container> &ms)
{
	typename MutantStack<T, Container>::const_iterator it = ms.begin();
	typename MutantStack<T, Container>::const_iterator ite = ms.end();

	os << "[ ";
	for (; it < ite; ++it)
		os << *it << " ";

	os << "]";
	return os;
}
