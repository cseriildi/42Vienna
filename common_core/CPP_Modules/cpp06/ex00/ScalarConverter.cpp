#include "ScalarConverter.hpp"
#include "utils.hpp"
#include <string>
#include <iostream>
#include <typeinfo>

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
		default: throw std::bad_cast();
		}
	} catch (std::bad_cast &e) {

		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
	}
}
