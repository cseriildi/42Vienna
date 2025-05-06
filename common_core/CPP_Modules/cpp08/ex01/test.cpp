//NOLINTBEGIN(readability-magic-numbers, misc-use-internal-linkage, misc-use-anonymous-namespace)

#include "Span.hpp"
#include "../colors.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <vector>

void test_from_subject(void)
{
	std::cout << UNDERLINED BOLD BLUE "Test from subject\n" RESET;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl; //NOLINT
	std::cout << sp.longestSpan() << std::endl; //NOLINT
}
void test_addNumber(void)
{
	std::cout << UNDERLINED BOLD BLUE "\nTest addNumber()\n" RESET;

	Span sp = Span();
	try {
		std::cout << sp << " capacity: " << sp.size() << "\ntrying to add a number -> ";
		sp.addNumber(rand());
		std::cout << sp << "\n";
	} catch (const std::out_of_range &e) {
		std::cout << RED << e.what() << RESET "\n";
	}

	Span sp1 = Span(1);
	try {
		std::cout << sp1 << " capacity: " << sp1.size() << "\ntrying to add a number -> ";
		sp1.addNumber(rand());
		std::cout << sp1 << "\ntrying to add another number -> ";
		sp1.addNumber(rand());
		std::cout << sp1 << "\n";
	} catch (const std::out_of_range &e) {
		std::cout << RED << e.what() << RESET "\n";
	}
}

void test_addNumbers(void)
{
	std::cout << UNDERLINED BOLD BLUE "\nTest addNumbers()\n" RESET;

	Span sp = Span(100000);
	std::cout << "filled: " << sp.count() << "/" << sp.size() << "\n";

	std::cout << BOLD CYAN "\naddNumbers() range(100) as vector\n" RESET;
	sp.addNumbers(range(100));
	std::cout << sp << "\n";
	std::cout << "filled: " << sp.count() << "/" << sp.size() << "\n";

	std::cout << BOLD CYAN "\naddNumbers() range(0, -200, -2) with Iterators\n" RESET;
	const std::vector<int> vec = range(0, -200, -2);
	sp.addNumbers(vec.begin(), vec.end());
	std::cout << sp << "\n";
	std::cout << "filled: " << sp.count() << "/" << sp.size() << "\n";

	std::cout << BOLD CYAN "\naddNumbers() vector of random numbers\n" RESET;
	std::vector<int> vec2;
	vec2.reserve(100);
	for (int i = 0; i < 100; ++i)
		vec2.push_back(rand() % 1000);
	sp.addNumbers(vec2);
	std::cout << sp << "\n";
	std::cout << "filled: " << sp.count() << "/" << sp.size() << "\n";

	try {
		std::cout << BOLD CYAN "\naddNumbers() range(10000000)\n" RESET;
		sp.addNumbers(range(10000000));
	} catch (const std::out_of_range &e) {
		std::cout << RED << e.what() << RESET "\n";
	}

	std::cout << BOLD CYAN "\naddNumbers() to fill the whole span\n" RESET;
	std::cout << "BEFORE: " << sp.count() << "/" << sp.size() << "\n";
	sp.addNumbers(range(99700));
	std::cout << "AFTER: " << sp.count() << "/" << sp.size() << "\n";
}

static void testSpans(Span sp)
{
	try {
		std::cout << "shortestSpan() of " << sp << " -> ";
		std::cout << sp.shortestSpan() << "\n";
	} catch (const std::logic_error &e) {
		std::cout << RED << e.what() << RESET "\n";
	}
	try {
		std::cout << "longestSpan() of " << sp << " -> ";
		std::cout << sp.longestSpan() << "\n";
	} catch (const std::logic_error &e) {
		std::cout << RED << e.what() << RESET "\n";
	}
}

void test_shortestLongestSpan(void)
{
	std::cout << UNDERLINED BOLD BLUE "\nTest shortestSpan() and longestSpan()\n" RESET;
	Span sp = Span(25); 
	testSpans(sp);
	for (int i = 0; i < 5; ++i)
	{
		sp.addNumber(rand() % 100);
		testSpans(sp);
	}
	sp.addNumbers(range(-1000, 1000, 100));
	testSpans(sp);
}

//NOLINTEND(readability-magic-numbers, misc-use-internal-linkage, misc-use-anonymous-namespace)
