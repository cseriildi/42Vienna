#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

enum NumberType {
	CHAR,
	INTEGER,
	FLOAT,
	DOUBLE,
	NaN
};

NumberType detect_type(const std::string& str);

template <typename T, typename F>
struct is_same {
	static const bool value = false;
};

template <typename T>
struct is_same<T, T> {
	static const bool value = true;
};

template<typename T>
T sto(const std::string& str);

void detect_and_cast(const std::string& from);

template <typename T>
bool is_nan(T num);

template <typename T, typename F>
bool is_overflow(F from);

template <typename T, typename F>
T try_cast(const F& from);

template <typename T, typename F>
void print_cast(const F& from);

template <typename F>
void print_all(const F& from);

#include "utils.tpp" // IWYU pragma: export

#endif
