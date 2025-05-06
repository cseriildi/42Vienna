#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <ostream>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int N) : _size(N) {}

Span::Span(const Span &other) : _size(other._size), _array(other._array) {}

Span::~Span() {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_size = other._size;
		_array = other._array;
	}
	return *this;
}

unsigned int Span::count() const {return _array.size();}

unsigned int Span::size() const {return _size;}

std::vector<int> Span::array() const {return _array;}

void Span::clear() {_array.clear();}

void Span::addNumber(int n)
{
	if (count() == _size)
		throw std::out_of_range("Span is full");
	_array.push_back(n);

	std::sort(_array.begin(), _array.end());
}

void Span::addNumbers(std::vector<int>& vec) {addNumbers(vec.begin(), vec.end());}

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	unsigned int size = std::distance(begin, end);
	if (count() + size > _size)
		throw std::out_of_range("Can't add all the numbers");
	_array.insert(_array.end(), begin, end);

	std::sort(_array.begin(), _array.end());
}

unsigned int Span::shortestSpan()
{
	long min = Span::longestSpan();

	for (unsigned int i = 1; i < count(); ++i){
		min = std::min(min, (long)(_array[i]) - _array[i - 1]);
	}
	return min;
}

unsigned int Span::longestSpan()
{
	if (count() < 2)
		throw std::logic_error("Not enough elements to find a span");

	return (long)(_array.back()) - _array.front();
}

std::vector<int> range(int start, int end, int step)
{
	if (step == 0)
		throw std::invalid_argument("Step must not be zero");

	std::vector<int> result;
	for (int i = start; (step > 0) ? (i < end) : (i > end); i += step)
		result.push_back(i);
	return result;
}

std::vector<int> range(int end) {return range(0, end);}

std::ostream& operator<<(std::ostream& os, const Span& other)
{
	std::vector<int> arr = other.array();
	os << "Span: [ ";
	for (unsigned int i = 0; i < other.count(); ++i)
		os << arr[i] << " ";

	os << "]";
	return os;
}
