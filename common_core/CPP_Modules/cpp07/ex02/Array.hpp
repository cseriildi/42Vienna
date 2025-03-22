#pragma once

#include <ostream>
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

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n)
{
	for (unsigned int i = 0; i < n; ++i)
		_arr[i] = T();
}

template <typename T>
Array<T>::~Array() {delete[] _arr;}

template <typename T>
Array<T>::Array(const Array &other)
{
	_size = other.size();
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; ++i)
		_arr[i] = other[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return *this;
	delete[] _arr;
	_size = other.size();
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; ++i)
		_arr[i] = other[i];
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) const
{
	if (i >= size())
		throw std::out_of_range("Index out of range");
	return _arr[i];
}

template <typename T>
unsigned int Array<T>::size(void) const {return _size;}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& other)
{
    for (unsigned int i = 0; i < other.size(); ++i)
    {
		if (i != 0)
			os << ", ";
        os << other[i];
    }
	os << "\n";
    return os;
}
