#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

template <typename T>
class Array
{
	public:
		Array(unsigned int n = 0);
		~Array();
		Array(const Array &other);
		Array &operator=(const Array &other);
		T &operator[](unsigned int i) const;

		unsigned int size(void) const;

	private:
		T 		*_arr;
		size_t	_size;
};

#include "Array.tpp" // IWYU pragma: export

#endif
