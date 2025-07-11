#pragma once

#include <list>
#include <ostream>
#include <stack>
#include <string>

typedef std::list<double> Container;

class RPN {
public:
  RPN(const char *expression);
  ~RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);

  const std::string &expression() const;
  double solve();

private:
  RPN();
  void doOperation(char op);
  void storeNumber(std::string::const_iterator it);
  double poptop();
  static bool isOperator(char op);

  std::stack<double, Container> _numbers;
  std::string _expression;
  static const std::string _operators;
};

std::ostream &operator<<(std::ostream &os, const RPN &other);
void run_tests(void);
