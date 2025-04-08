//NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers, cppcoreguidelines-pro-bounds-array-to-pointer-decay)
#include "../colors.hpp"
#include "iter.hpp"
#include <cctype>
#include <cmath>
#include <iostream>

namespace
{
	template <typename T>
	void display(const T& t) {std::cout << t << "\n";}
	
	template <typename T>
	void increment(T& x) {++x;}

	void square(int &i) {i = static_cast<int>(std::sqrt(i));}
	void upper(char &c) {c = static_cast<char>(std::toupper(c));}

	struct TestStruct {
		int value; //NOLINT
		
		TestStruct(int v) : value(v) {}
		TestStruct	&operator++() {++value; return *this;}
	};

	std::ostream& operator<<(std::ostream& os, const TestStruct& other){
		return os << other.value;
	}
}

void int_arr_test(void)
{
	std::cout << BOLD UNDERLINED "Int array test:\n" RESET;

	int arr1[] = {42, 56, 71, 102};
	
	::iter(arr1, 12, display<int>);
	std::cout << "\n";
	::iter(arr1, 12, square);
	::iter(arr1, 12, display<int>);
	std::cout << "\n";
	::iter(arr1, 12, increment<int>);
	::iter(arr1, 2, display<int>);
	std::cout << "\n";
}

void char_arr_test(void)
{
	std::cout << BOLD UNDERLINED "Char array test:\n" RESET;

	char arr2[] = "Hello";

	::iter(arr2, 5, display<char>);
	std::cout << "\n";
	::iter(arr2, 15, upper);
	::iter(arr2, 5, display<char>);
	std::cout << "\n";
	::iter(arr2, 10, increment<char>);
	::iter(arr2, 2, display<char>);
	std::cout << "\n";
}

void struct_arr_test(void)
{
	std::cout << BOLD UNDERLINED "Struct array test:\n" RESET;

	TestStruct arr3[] = {TestStruct(1), TestStruct(2), TestStruct(3)};

	::iter(arr3, 3, display<TestStruct>);
	std::cout << "\n";
	::iter(arr3, 13, increment<TestStruct>);
	::iter(arr3, 2, display<TestStruct>);
}
//NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers, cppcoreguidelines-pro-bounds-array-to-pointer-decay)
