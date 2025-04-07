//NOLINTBEGIN(readability-magic-numbers)

#include "ScalarConverter.hpp"
#include "../colors.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

void test_convert(const std::string& str)
{
	std::cout << PURPLE "\"" << str << "\" converted to:\n" RESET;
	ScalarConverter::convert(str);
	std::cout << "\n";
}

template <typename F>
void test_convert(F from)
{
	std::stringstream ss;
	ss << std::fixed << std::setprecision(1) << from;
	test_convert(ss.str());
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
	test_convert("99");
	test_convert("-99");
	test_convert(std::numeric_limits<int>::max());
	test_convert(std::numeric_limits<int>::min());
	test_convert(std::numeric_limits<int>::max() + 1.);
	test_convert(std::numeric_limits<int>::min() - 1.);
}


void test_specials(void)
{
	std::cout << BOLD UNDERLINED "Special tests\n" RESET;
	test_convert("inf");
	test_convert("inff");
	test_convert("-inf");
	test_convert("-inff");
	test_convert("nan");
	test_convert("nanf");
}
void test_floats(void)
{
	std::cout << BOLD UNDERLINED "Float tests\n" RESET;
	test_convert("124.151f");
	test_convert(".5f");
	test_convert("60.f");
	test_convert("-.0f");
	test_convert(std::numeric_limits<float>::max());
	test_convert(-std::numeric_limits<float>::max());
	test_convert(static_cast<double>(std::numeric_limits<float>::max()) * 1.1);
	test_convert(-static_cast<double>(std::numeric_limits<float>::max()) * 1.1);
}

void test_doubles(void)
{
	std::cout << BOLD UNDERLINED "Double tests\n" RESET;
	test_convert("99.");
	test_convert("-99.");
	test_convert("50.");
	test_convert(".9");
	test_convert(std::numeric_limits<double>::max());
	test_convert(-std::numeric_limits<double>::max());
	test_convert(std::numeric_limits<double>::max() * 1.1L);
	test_convert(-std::numeric_limits<double>::max() * 1.1L);
}

void test_invalid(void)
{
	std::cout << BOLD UNDERLINED "Invalid input\n" RESET;
	test_convert("");
	test_convert("99f");
	test_convert("-99f");
	test_convert(".f");
	test_convert("abc");
	test_convert("54.5t");
	test_convert("54.5ff");
	test_convert("54..5f");
	test_convert("54fngkd");
}

//NOLINTEND(readability-magic-numbers)
