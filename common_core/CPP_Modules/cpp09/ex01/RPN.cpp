// NOLINTBEGIN(readability-implicit-bool-conversion)
#include "RPN.hpp"
#include "../colors.hpp"

#include <cctype>
#include <ostream>
#include <stdexcept>
#include <string>

const std::string RPN::_operators = "+-*/";

RPN::RPN(const char *expression) : _expression(expression) {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
    : _numbers(other._numbers), _expression(other._expression) {}

RPN &RPN::operator=(const RPN &other) {
  if (this != &other) {
    _expression = other._expression;
    _numbers = other._numbers;
  }
  return *this;
}

double RPN::solve() {
  std::string::const_iterator it;

  for (it = _expression.begin(); it != _expression.end(); it++) {
    if (std::isdigit(*it))
      storeNumber(it);
    else if (isOperator(*it))
      doOperation(*it);
    else if (!std::isspace(*it))
      throw std::logic_error("Invalid format");
  }

  if (_numbers.size() > 1)
    throw std::logic_error("Too many operands");

  return poptop();
}

double RPN::poptop() {
  if (_numbers.empty())
    throw std::logic_error("Not enough operands");

  const double top = _numbers.top();
  _numbers.pop();

  return top;
}

void RPN::storeNumber(std::string::const_iterator it) {
  if ((it + 1) != _expression.end() && std::isdigit(*(it + 1)))
    throw std::logic_error("Numbers should be between 0 and 9");

  _numbers.push(*it - '0');
}

void RPN::doOperation(char op) {
  const double b = poptop();
  const double a = poptop();

  if (op == '+')
    _numbers.push(a + b);
  else if (op == '-')
    _numbers.push(a - b);
  else if (op == '*')
    _numbers.push(a * b);
  else {
    if (b == 0)
      throw std::runtime_error("Division by 0");
    _numbers.push(a / b);
  }
}

bool RPN::isOperator(char op) {
  return _operators.find(op) != std::string::npos;
}

const std::string &RPN::expression() const { return _expression; }

std::ostream &operator<<(std::ostream &os, const RPN &other) {
  return os << BLUE "\"" << other.expression() << "\"\n" RESET;
}

// NOLINTEND(readability-implicit-bool-conversion)
