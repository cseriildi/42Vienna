#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyFind(T& cont, int n)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end())
		throw std::runtime_error("Element not found");
	return it;
}

template <typename T>
typename T::const_iterator easyFind(const T& cont, int n)
{
	typename T::const_iterator it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end())
		throw std::runtime_error("Element not found");
	return it;
}
