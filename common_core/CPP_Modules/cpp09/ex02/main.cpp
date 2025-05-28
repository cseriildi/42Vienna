
#include "PmergeMe.hpp"
#include <bits/types/struct_timeval.h>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <sys/time.h>

long now_in_microseconds()
{
    timeval tv; //NOLINT
    gettimeofday(&tv, 0);
    return tv.tv_sec * 1000000L + tv.tv_usec; //NOLINT
}

int main(int argc, char **argv) try {
	if (argc < 2)
		throw std::invalid_argument("Usage: ./PmergeMe <positive integers>");

	PmergeMe FJ(argc, argv);

	std::cout << "Before: " << FJ;

	long start = now_in_microseconds();
	FJ.sortVec();
	long vec_sort_time = now_in_microseconds() - start;

	FJ.empty_cache();

	start = now_in_microseconds();
	FJ.sortDeq();
	long deq_sort_time = now_in_microseconds() - start;

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
