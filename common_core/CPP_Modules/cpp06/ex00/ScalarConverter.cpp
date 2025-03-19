#include "ScalarConverter.hpp"
#include <iomanip>
#include <string>
#include <iostream>
#include <float.h>
#include <limits.h>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {(void)other; return *this;}

void print_c(double d)
{
	std::cout << "char: ";

	if (d > CHAR_MAX || d < CHAR_MIN || isnan(d))
		std::cout << "impossible\n";
	else if (!isprint(d))
		std::cout << "Non displayable\n";
	else
		std::cout << static_cast<char>(d) << "\n";
}

void print_i(double d)
{
	std::cout << "int: ";
	if (d > INT_MAX || d < INT_MIN || isnan(d))
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(d) << "\n";
}

void print_f(double d)
{
	std::cout << "float: ";
	//maybe not let it overflow into infinity
	std::cout << static_cast<float>(d) << "f\n";
}
void ScalarConverter::convert(const std::string& str)
{
    std::stringstream ss(str);

    double d;
	float f = 67.f;

	if (str.length() == 1 && !isdigit(str[0])) {
		d = static_cast<double>(str[0]);
	}
	else if (str == "nan" || str == "nanf") {
		d = NAN;
	}
	else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff") {
		d = INFINITY;
	}
	else if (str == "-inf" || str == "-inff") {
		d = -INFINITY;
	}
	else {
		if (str.find('.') && str[str.length() - 1] == 'f') {
			std::string tmp = str.substr(0, str.length() - 1);
			ss.str(tmp);
		}
		//check if the format is like a number
		//check if it fits into double
		ss >> d;
	} 


	print_c(d);
	print_i(d);
	std::cout << std::fixed << std::setprecision(1);
	print_f(d);
    std::cout << "double: " << d << std::endl;
}
