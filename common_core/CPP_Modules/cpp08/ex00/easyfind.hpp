#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(const T& cont, int n)
{
	typename T::const_iterator it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end())
		throw std::runtime_error("Element not found");
	return it;
}
