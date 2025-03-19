#include "ScalarConverter.hpp"
#include "../colors.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include "limits.h"
#include "float.h"

void test_convert(const std::string& str)
{
	std::cout << PURPLE "\""<< str << "\" converted to:\n" RESET;
	ScalarConverter::convert(str);
	std::cout << "\n";
}

void test_convert(double num)
{
	std::stringstream ss;
	ss << std::fixed << std::setprecision(0) << num;
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

	std::cout << "\n" BOLD UNDERLINED "Digit chars are considered int\n" RESET;
	test_convert("5");
	test_convert("0");

	std::cout << "\n" BOLD UNDERLINED "Integers that fit into char\n" RESET;
	test_convert("31");
	test_convert("32");
	test_convert("42");
	test_convert("126");
	test_convert("127");
	test_convert("-42");
}

void test_ints(void)
{
	std::cout << "\n" BOLD UNDERLINED "Integer tests\n" RESET;
	test_convert("999");
	test_convert("-999");
	test_convert(std::numeric_limits<int>::max());
	test_convert(std::numeric_limits<int>::min());
	test_convert(static_cast<float>(std::numeric_limits<int>::max()) + 1);
	test_convert(static_cast<float>(std::numeric_limits<int>::min()) - 1);
}

void test_floats(void)
{
	std::cout << "\n" BOLD UNDERLINED "Float tests\n" RESET;
	test_convert("999f");
	test_convert("-999f");
	test_convert("195.151f");
	test_convert(".f");
	test_convert(".5f");
	test_convert("6.f");
	test_convert("-.0f");
	test_convert(std::numeric_limits<float>::max());
	test_convert(-std::numeric_limits<float>::max());
	test_convert(static_cast<double>(std::numeric_limits<float>::max()) * 1.1);
	test_convert(-static_cast<double>(std::numeric_limits<float>::max()) * 1.1);
	test_convert("inff");
	test_convert("-inff");
	test_convert("nanf");


}

void test_doubles(void)
{
	std::cout << "\n" BOLD UNDERLINED "Double tests\n" RESET;
	test_convert("999");
	test_convert("-999");
	test_convert("5.");
	test_convert(".9");
	test_convert(std::numeric_limits<double>::max());
	test_convert(-std::numeric_limits<double>::max());
	test_convert("1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583690");
	test_convert("-1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583690");
	test_convert("inf");
	test_convert("-inf");
	test_convert("nan");
}

