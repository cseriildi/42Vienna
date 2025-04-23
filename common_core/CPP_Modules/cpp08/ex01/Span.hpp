#pragma once

#include <iterator>
#include <stdexcept>
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
		
	private:
		unsigned int		_size;
		std::vector<int>	_array;
};

std::vector<int> range(int start, int end, int step = 1);
std::vector<int> range(int end);
