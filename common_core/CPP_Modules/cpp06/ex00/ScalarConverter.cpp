#include "ScalarConverter.hpp"
#include "utils.hpp"
#include <stdexcept>
#include <string>
#include <iostream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {(void)other; return *this;}

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
	}
}
