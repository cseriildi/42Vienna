#pragma once

#include <ostream>
#include <vector>

class Span
{
	public:
		Span(unsigned int N=0);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &other);
		
		void			addNumber(int n);
		void			addNumbers(std::vector<int>& vec);
		
		template <typename Iterator>
		void			addNumbers(Iterator begin, Iterator end);

		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		
		unsigned int	count() const;
		unsigned int	size() const;
		std::vector<int> array() const;

		void			clear();
		
	private:
		unsigned int		_size;
		std::vector<int>	_array;
};

std::ostream& operator<<(std::ostream& os, const Span& other);

std::vector<int> range(int start, int end, int step = 1);
std::vector<int> range(int end);
