
#include "PmergeMe.hpp"
#include "utils.hpp"

#include <exception>
#include <iostream>
#include <stdexcept>
#include <sys/_types/_timeval.h>
#include <sys/time.h>

int main(int argc, char **argv) try {
  if (argc < 2)
    throw std::invalid_argument("Usage: ./PmergeMe <positive integers>");

  const Vec vec = parse_input(argc, argv);
  long start = now_in_microseconds();
  const Vec sortedVec = PmergeMe::mergeInsertionSort(vec);
  const long vec_sort_time = now_in_microseconds() - start;

  std::cout << "Before: " << vec << "\n";
  std::cout << "After: " << sortedVec << "\n";
  std::cout << "Time to process a range of " << argc - 1
            << " elements with std::vector : " << vec_sort_time << " us\n";

  const Deq deq(vec.begin(), vec.end());
  start = now_in_microseconds();
  const Deq sortedDeq = PmergeMe::mergeInsertionSort(deq);
  const long deq_sort_time = now_in_microseconds() - start;

#ifdef DEBUG
  std::cout << "Before: " << deq << "\n";
  std::cout << "After: " << sortedDeq << "\n";
#endif

  std::cout << "Time to process a range of " << argc - 1
            << " elements with std::deque : " << deq_sort_time << " us\n";

  return 0;

} catch (const std::exception &e) {
  std::cerr << e.what() << "\n";
  return 1;
} catch (...) {
  std::cout << "Unknown error\n";
  return 1;
}
