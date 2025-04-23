//NOLINTBEGIN(readability-magic-numbers)

#include "easyfind.hpp"
#include "../colors.hpp"

#include <cstdlib>
#include <ctime>
#include <deque>
#include <exception>
#include <list>
#include <vector>
#include <iostream>

template <typename T>
void print_cont(const T& cont)
{
	std::cout << "[ ";
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout << *it << " ";
	std::cout << "]\n";
}

template <typename T>
void fill_cont(T &cont)
{
	for (int i = 0; i < 5; ++i)
		cont.push_back(std::rand() % 5);
}

template <typename T>
void test(const T& cont, int n)
{
	std::cout << "Looking for " << n << " in: ";
	print_cont(cont);
	try {
		typename T::const_iterator it = easyfind(cont, n);
		std::cout << GREEN "Found: " << *it << " at index " << std::distance(cont.begin(), it) << RESET "\n";
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET "\n";
	}
}

int main(void)
{
	std::srand(std::time(0));

	std::cout << BOLD UNDERLINED "Test vector" RESET << "\n";
	std::vector<int> vec;
	test(vec, 0);
	fill_cont(vec);
	for (int i = 0; i < 5; ++i)
		test(vec, i);

	std::cout << BOLD UNDERLINED "\nTest list" RESET << "\n";
	std::list<int> lst;
	test(lst, 0);
	fill_cont(lst);
	for (int i = 0; i < 5; ++i)
		test(lst, i);

	std::cout << BOLD UNDERLINED "\nTest deque" RESET << "\n";
	std::deque<int> deq;
	test(deq, 0);
	fill_cont(deq);
	for (int i = 0; i < 5; ++i)
		test(deq, i);

	return 0;
}
//NOLINTEND(readability-magic-numbers)
