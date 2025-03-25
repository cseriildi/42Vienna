#include "ScalarConverter.hpp"
#include "../colors.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

void test_convert(const std::string& str)
{
	std::cout << PURPLE "\""<< str << "\" converted to:\n" RESET;
	ScalarConverter::convert(str);
	std::cout << "\n";
}

void test_convert(long double num)
{
	std::stringstream ss;
	ss << std::fixed << std::setprecision(0) << num;
	test_convert(ss.str());
}

float epsilon(float num)
{
	float prev = nextafterf(num, -std::numeric_limits<float>::infinity());
	if (prev != -std::numeric_limits<float>::infinity())
		return num - prev;
	return nextafterf(num, std::numeric_limits<float>::infinity()) - num;
}

double epsilon(double num)
{
	double prev = nextafter(num, -std::numeric_limits<double>::infinity());
	if (prev != -std::numeric_limits<double>::infinity())
		return num - prev;
	return nextafter(num, std::numeric_limits<double>::infinity()) - num;
}

void test_chars(void)
{
	std::cout << BOLD UNDERLINED "Valid chars\n" RESET;
	test_convert(" ");
	test_convert("*");
	test_convert("f");
	test_convert("~");
	test_convert(".");

	std::cout << BOLD UNDERLINED "Digit chars are considered int\n" RESET;
	test_convert("5");
	test_convert("0");

	std::cout << BOLD UNDERLINED "Integers that fit into char\n" RESET;
	test_convert("31");
	test_convert("32");
	test_convert("42");
	test_convert("126");
	test_convert("127");
	test_convert("-42");
}

void test_ints(void)
{
	std::cout << BOLD UNDERLINED "Integer tests\n" RESET;
	test_convert("999");
	test_convert("-999");
	test_convert(std::numeric_limits<int>::max());
	test_convert(std::numeric_limits<int>::min());
	test_convert(static_cast<float>(std::numeric_limits<int>::max()) + 1);
	test_convert(static_cast<float>(std::numeric_limits<int>::min()) - 1);
}

void test_floats(void)
{
	std::cout << BOLD UNDERLINED "Float tests\n" RESET;
	test_convert("195.151f");
	test_convert(".5f");
	test_convert("6.f");
	test_convert("-.0f");
	test_convert(std::numeric_limits<float>::max());
	test_convert(-std::numeric_limits<float>::max());
	test_convert(static_cast<double>(std::numeric_limits<float>::max())
							+ epsilon(std::numeric_limits<float>::max()));
	test_convert(-static_cast<double>(std::numeric_limits<float>::max())
							- epsilon(std::numeric_limits<float>::max()));
	test_convert("inff");
	test_convert("-inff");
	test_convert("nanf");
}

void test_doubles(void)
{
	std::cout << BOLD UNDERLINED "Double tests\n" RESET;
	test_convert("999");
	test_convert("-999");
	test_convert("5.");
	test_convert(".9");
	test_convert(std::numeric_limits<double>::max());
	test_convert(-std::numeric_limits<double>::max());
	test_convert(static_cast<long double>(std::numeric_limits<double>::max())
							+ epsilon(std::numeric_limits<double>::max()));
	test_convert(-static_cast<long double>(std::numeric_limits<double>::max())
							- epsilon(std::numeric_limits<double>::max()));
	test_convert("-inf");
	test_convert("nan");
}

void test_invalid(void)
{
	std::cout << BOLD UNDERLINED "Invalid input\n" RESET;
	test_convert("");
	test_convert("999f");
	test_convert("-999f");
	test_convert(".f");
	test_convert("abc");
	test_convert("54.5t");
	test_convert("54.5ff");
	test_convert("54..5f");
	test_convert("54fngkd");
}
