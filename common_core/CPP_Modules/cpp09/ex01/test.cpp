#include "../colors.hpp"
#include "RPN.hpp"

#include <exception>
#include <iostream>

static void test(const char *expression) try {
  RPN rpn(expression);
  std::cout << rpn << rpn.solve() << "\n";

} catch (const std::exception &e) {
  std::cout << RED << e.what() << RESET "\n";
}

void run_tests(void) {
  std::cout << BOLD UNDERLINED "\nTest from subject\n" RESET;

  test("8 9 * 9 - 9 - 9 - 4 - 1 +");
  test("7 7 * 7 -");
  test("1 2 * 2 / 2 * 2 4 - +");
  test("(1 + 1)");

  std::cout << BOLD UNDERLINED "\nTest too many operands\n" RESET;
  test("1 2 3+");
  test("1 2");

  std::cout << BOLD UNDERLINED "\nTest not enough operands\n" RESET;
  test("1 2 3+++");
  test("");

  std::cout << BOLD UNDERLINED "\nTest invalid number\n" RESET;
  test("11 2+");

  std::cout << BOLD UNDERLINED "\nTest invalid format\n" RESET;
  test("1 2 plus");
  test("1 2 %");
  test("1.5 2 +");

  std::cout << BOLD UNDERLINED "\nTest valid expressions\n" RESET;
  test("4");
  test(" 4 5 +");
  test("4 5 - ");
  test("4   5 *");
  test("0 4 /");
  test("4 0 /");
}
