//NOLINTBEGIN(readability-implicit-bool-conversion, misc-use-anonymous-namespace)
#include <cctype>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>

static double poptop(std::stack<double>& stack)
{
	if (stack.empty())
		throw std::logic_error("Not enough operands");

	double top = stack.top();
	stack.pop();

	return top;
}

void rpn(const std::string &expression)
{
	std::string::const_iterator it;
	std::stack<double> numbers;
	std::string operators("+-*/");

	for (it = expression.begin(); it != expression.end(); it++)
	{
		if (std::isdigit(*it))
		{
			if ((it + 1) != expression.end() && std::isdigit(*(it + 1)) == 1)
				throw std::logic_error("Numbers should be between 0 and 9");
			
			numbers.push(*it - '0');
			continue;
		}

		if (std::isspace(*it))
			continue;
		
		if (operators.find(*it) == std::string::npos)
			throw std::logic_error("Not valid format");

		double b = poptop(numbers);
		double a = poptop(numbers);

		if (*it == '+') 
			numbers.push(a + b);
		else if (*it == '-')
			numbers.push(a - b);
		else if (*it == '*')
			numbers.push(a * b);
		else
		{
			if (b == 0)
				throw std::runtime_error("Division by 0");
			numbers.push(a / b);
		}
	}
	if (numbers.size() != 1)
		throw std::logic_error("Too many operands");
	std::cout << "Result: " << poptop(numbers) << "\n";
}

//NOLINTEND(readability-implicit-bool-conversion, misc-use-anonymous-namespace)
