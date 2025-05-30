//NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic)

#pragma once

#ifndef ARRAY_HPP
#include "Array.hpp"
#endif

#include <ostream>
#include <stdexcept>

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _arr(new T[n])
{
	for (unsigned int i = 0; i < n; ++i)
		_arr[i] = T();
}

template <typename T>
Array<T>::~Array() { delete[] _arr; }

template <typename T>
Array<T>::Array(const Array &other) : _size(other._size), _arr(new T[other._size])
{
	for (unsigned int i = 0; i < _size; ++i)
		_arr[i] = other._arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return *this;
	delete[] _arr;
	_size = other._size;
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; ++i)
		_arr[i] = other._arr[i];
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::out_of_range("Index out of range");
	return _arr[i];
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::out_of_range("Index out of range");
	return _arr[i];
}

template <typename T>
unsigned int Array<T>::size(void) const { return _size; }

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

//NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic)
