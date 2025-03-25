#include "ScalarConverter.hpp"
#include <cctype>
#include <iomanip>
#include <limits>
#include <string>
#include <iostream>
#include <float.h>
#include <limits.h>
#include <cmath>
#include <sstream>
#include <math.h>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {(void)other; return *this;}

void print_c(double d)
{
	std::cout << "char: ";

	if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min()
		|| (isnan(d) != 0))
		std::cout << "impossible\n";
	else if (isprint(static_cast<int>(d)) == 0)
		std::cout << "Non displayable\n";
	else
		std::cout << static_cast<char>(d) << "\n";
}

void print_i(double d)
{
	std::cout << "int: ";

	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()
		|| (isnan(d) != 0))
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(d) << "\n";
}

void print_f(double d)
{
	std::cout << "float: ";

	float f = static_cast<float>(d);
	
	if (d != std::numeric_limits<double>::infinity()
		&& d != -std::numeric_limits<double>::infinity()
		&& (f == std::numeric_limits<float>::infinity()
			|| f == -std::numeric_limits<float>::infinity()))
		std::cout << "impossible\n";
	else
		std::cout << f << "f\n";
}

bool is_numeric(const std::string& str)
{
	int dot_count = 0;
	int sign = static_cast<int>(*str.begin() == '+' || *str.begin() == '-');

	for (std::string::const_iterator it = str.begin() + sign; it != str.end(); it++)
	{
		if (isdigit(*it) == 0)
		{
			if (*it == '.')
			{
				if (++dot_count > 1)
					return false;
				continue;
			}
			if (*it == 'f' && it + 1 == str.end()
				&& dot_count == 1
				&& str.length() - sign - dot_count > 1)
				break;
			return false;
		}
	}
	return true;
}

void print_all(double d, bool possible)
{
	if (possible)
	{
		print_c(d);
		print_i(d);
		std::cout << std::fixed << std::setprecision(1);
		print_f(d);
		std::cout << "double: " << d << "\n";
	}
	else
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
	}
}

void ScalarConverter::convert(const std::string& str)
{
    std::stringstream ss(str);
    double d = 0;
	ss >> d;

	if (str.length() == 1 && (isdigit(str[0]) == 0)) {
		d = static_cast<double>(str[0]);
	}
	else if (str == "nan" || str == "nanf") {
		d = NAN;
	}
	else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff") {
		d = std::numeric_limits<double>::infinity();
	}
	else if (str == "-inf" || str == "-inff") {
		d = -std::numeric_limits<double>::infinity();
	}
	else if (ss.fail() || !is_numeric(ss.str()))
	{
		print_all(d, false);
		return;
	}
	print_all(d, true);
}
