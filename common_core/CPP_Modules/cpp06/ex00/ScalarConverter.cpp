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
#include <math.h>

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
	float f = static_cast<float>(d);
	std::cout << "float: ";
	if (d != INFINITY && d != -INFINITY && (f == INFINITY || f == -INFINITY))
		std::cout << "impossible\n";
	else
		std::cout << f << "f\n";
}

bool is_numeric(const std::string& str)
{
	int dot_count = 0;
	bool sign = (*str.begin() == '+' || *str.begin() == '-');
	

	std::string::const_iterator it;

	for (it = str.begin() + sign; it != str.end(); it++)
	{
		if (!isdigit(*it))
		{
			if (*it == '.')
			{
				if (++dot_count > 1)
					return false;
				continue;
			}
			else if (*it == 'f' && it + 1 == str.end()
				&& dot_count == 1
				&& str.length() - sign - dot_count > 1)
				return true;

			return false;
		}
	}
	return true;
}

void ScalarConverter::convert(const std::string& str)
{
    std::stringstream ss(str);

    double d;

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
		ss >> d;
		if (ss.fail() || !is_numeric(ss.str()))
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible\n";
			return;
		}
	} 

	print_c(d);
	print_i(d);
	std::cout << std::fixed << std::setprecision(1);
	print_f(d);
    std::cout << "double: " << d << std::endl;
}
