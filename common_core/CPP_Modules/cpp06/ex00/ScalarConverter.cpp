#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {(void)other; return *this;}

void ScalarConverter::convert(const std::string& str)
{
	std::cout << "char: " << str << "\n";
	std::cout << "int: " << str << "\n";
	std::cout << "float: " << str << "\n";
	std::cout << "double: " << str << "\n";
}
