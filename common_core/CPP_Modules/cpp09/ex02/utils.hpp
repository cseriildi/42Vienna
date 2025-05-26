#pragma once

#include "../colors.hpp"
#include <iostream>
#include <limits>
#include <ostream>
#include <sstream>
#include <string>
#include <typeinfo>

template<typename T>
T sto(const std::string& str) {
	if (str == "nan" || str == "nanf") {
		if (!std::numeric_limits<T>::has_quiet_NaN)
			throw std::bad_cast();
		return std::numeric_limits<T>::quiet_NaN();
	}
	if (str == "+inf" || str == "inf" || str == "+inff" || str == "inff") {
		if (!std::numeric_limits<T>::has_infinity)
			throw std::bad_cast();
		return std::numeric_limits<T>::infinity();
	}
	if (str == "-inf" || str == "-inff") {
		if (!std::numeric_limits<T>::has_infinity)
			throw std::bad_cast();
		return -std::numeric_limits<T>::infinity();
	}
	std::stringstream ss(str);
	T result;
	ss >> result;
	if (ss.fail() || !ss.eof()) {
		throw std::bad_cast();
	}
	return result;
}

template<typename Container>
void  print2D(const Container &cont, const std::string& color = RESET)
{
	typedef typename Container::const_iterator OuterIt;
    typedef typename Container::value_type InnerContainer;
    typedef typename InnerContainer::const_iterator InnerIt;

	std::cout << color << "{";
	for (OuterIt it = cont.begin(); it != cont.end(); it++)
	{
		std::cout << "[";
		for (InnerIt itt = (*it).begin(); itt != (*it).end(); itt++)
		{
			if (itt != (*it).begin())
				std::cout << " ";
			std::cout << *itt;
		}
		std::cout << "]";
	}
	std::cout << "}" RESET;
}

template<typename Container>
void  debug(const Container &cont, const Container &unmatched)
{
	print2D(cont, GREEN);
	print2D(unmatched, BLUE);
	std::cout << "\n";
}

template<typename Container>
void  debug(const Container &cont, const Container &cont2, const Container &unmatched)
{
	print2D(cont, GREEN);
	print2D(cont2, YELLOW);
	print2D(unmatched, BLUE);
	std::cout << "\n";
}
