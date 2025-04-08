#pragma once

#include <stdexcept>
#ifndef UTILS_HPP
#include "utils.hpp"
#endif

#include <iomanip>
#include <iostream>
#include <limits>
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
	if (ss.fail()) {
		throw std::bad_cast();
	}
	return result;
}

template <typename T>
bool is_nan(T num) {
	return num != num; // NOLINT
}

template <typename T, typename F>
bool is_overflow(F from) {
	if (std::numeric_limits<T>::is_integer)
		return from < std::numeric_limits<T>::min() || from > std::numeric_limits<T>::max() || is_nan(from);
	return (from < -std::numeric_limits<T>::max() || from > std::numeric_limits<T>::max())
		&& from != std::numeric_limits<F>::infinity() && from != -std::numeric_limits<F>::infinity();
}

template <typename T, typename F>
T try_cast(const F& from) {
	if (is_same<T, F>::value) {
		return from;
	}
	if (is_overflow<T>(from))
		throw std::out_of_range("impossible");
	if (is_same<T, char>::value && std::isprint(from) == 0)
		throw std::out_of_range("Non displayable");

	return static_cast<T>(from);
}

template <typename T, typename F>
void print_cast(const F& from)
{
	try {
		T t = try_cast<T>(from);
		std::cout << t;
		if (is_same<T, float>::value) {
			std::cout << "f";
		}
	} catch (const std::out_of_range &e) {
		std::cout << e.what();
	}
	std::cout << "\n";
}

template <typename F>
void print_all(const F& from)
{
	std::cout << "char: ";
	print_cast<char>(from);

	std::cout << "int: ";
	print_cast<int>(from);

	std::cout << "float: " << std::fixed << std::setprecision(1);
	print_cast<float>(from);

	std::cout << "double: ";
	print_cast<double>(from);
}
