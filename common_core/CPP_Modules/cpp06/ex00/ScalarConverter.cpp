#include "ScalarConverter.hpp"
#include "utils.hpp"
#include <cctype>
#include <stdexcept>
#include <string>
#include <iostream>
#include <typeinfo>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {(void)other; return *this;}

static NumberType detect_type(const std::string& str) //NOLINT
{
	if (str == "nan" || str == "+inf" || str == "inf" || str == "-inf") {
		return DOUBLE;
	}
	if (str == "nanf" || str == "+inff" || str == "inff" || str == "-inff") {
		return FLOAT;
	}
	if (str.empty()) {
		return NaN;
	}
	if (str.length() == 1 && isdigit(str[0]) == 0) {
		return CHAR;
	}
	int dot_count = 0;
	int sign = static_cast<int>(*str.begin() == '+' || *str.begin() == '-');

	for (std::string::const_iterator it = str.begin() + sign; it != str.end(); it++)
	{
		if (isdigit(*it) == 0)
		{
			if (*it == '.') {
				if (++dot_count > 1)
					return NaN;
				continue;
			}
			if (*it == 'f' && it + 1 == str.end()
				&& dot_count == 1
				&& str.length() - sign - dot_count > 1)
				return FLOAT;
			return NaN;
		}
	}
	return dot_count == 0 ? INTEGER : DOUBLE;
}

void ScalarConverter::convert(const std::string& str)
{
	try {
		switch (detect_type(str)) {
		case CHAR: print_all(str[0]);
			break;
		case INTEGER: print_all(sto<int>(str));
			break;
		case FLOAT: print_all(sto<float>(str));
			break;
		case DOUBLE: print_all(sto<double>(str));
			break;
		default: throw std::invalid_argument("char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");
		}
	} catch (const std::invalid_argument &e) {
		std::cout << e.what();;
	} catch (const std::bad_cast &) {
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
	}
}
