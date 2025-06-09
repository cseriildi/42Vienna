#include "../colors.hpp"
#include "RPN.hpp"

#include <exception>
#include <iostream>

int main(int argc, char **argv) try {
#ifdef DEBUG
  run_tests();
  return 0;
#endif

  if (argc != 2) {
    std::cout << "Usage: ./RPN <inverted Polish mathematical expression>\n";
    return (1);
  }
  std::cout << RPN(argv[1]).solve() << "\n";
  return 0;

} catch (const std::exception &e) {
  std::cout << RED << e.what() << RESET "\n";
  return (1);
} catch (...) {
  std::cout << RED "Unknown error\n" RESET;
  return (1);
}
