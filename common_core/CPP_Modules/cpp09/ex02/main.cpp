
#include "PmergeMe.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>
#include <ctime>

int main(int argc, char **argv) try {
	if (argc < 2)
		throw std::invalid_argument("Usage: ./PmergeMe <positive integers>");

	PmergeMe FJ(argv);

	std::cout << "Before: " << FJ;

	std::time_t start = std::time(0);
	FJ.sortVec();
	unsigned int vec_sort_time = std::time(0) - start;

	FJ.empty_cache();

	start = std::time(0);
	FJ.sortDeq();
	unsigned int deq_sort_time = std::time(0) - start;

	std::cout << "After: " << FJ;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << vec_sort_time << " us\n";
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << deq_sort_time << " us\n";

	return 0;

} catch (const std::exception &e) {
	std::cerr << e.what() << "\n";
	return 1;
} catch (...) {
	std::cout << "Unknown error\n";
	return 1;
}
