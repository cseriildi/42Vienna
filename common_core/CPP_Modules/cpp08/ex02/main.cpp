//NOLINTBEGIN(readability-magic-numbers)

#include "MutantStack.hpp"
#include "../colors.hpp"
#include <stack>
#include <iostream>
#include <vector>

int main(void)
{
	{
		std::cout << UNDERLINED BOLD "Test from subject\n" RESET;
		//NOLINTBEGIN
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		//NOLINTEND
	}
	{
		std::cout << UNDERLINED BOLD "\nMore tests\n" RESET;
		MutantStack<float> stack;
		std::cout << stack << " Stack is " << (stack.empty() ? "" : "not ") << "empty\n";
		stack.push(1.F);
		stack.push(42);
		stack.push(3.14F);
		std::cout << stack << " Stack is " << (stack.empty() ? "" : "not ") << "empty\n";

		
		std::cout << "\nForward iteration:\n";
		for (MutantStack<float>::iterator it = stack.begin(); it != stack.end(); ++it)
			std::cout << *it << " ";
		std::cout << "\n";

		std::cout << "Reverse iteration:\n";
		for (MutantStack<float>::reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it)
			std::cout << *it << " ";
		std::cout << "\n";

		std::cout << "Const forward iteration:\n";
		const MutantStack<float> const_stack = static_cast<const MutantStack<float> >(stack);
		for (MutantStack<float>::const_iterator it = const_stack.begin(); it != const_stack.end(); ++it)
			std::cout << *it << " ";
		std::cout << "\n";

		std::cout << "Const reverse iteration:\n";
		for (MutantStack<float>::const_reverse_iterator it = const_stack.rbegin(); it != const_stack.rend(); ++it)
			std::cout << *it << " ";
		std::cout << "\n";

		std::cout << "Stack size: " << stack.size() << "\n";
		std::cout << "Stack top: " << stack.top() << "\n";
		stack.pop();
		std::cout << "Stack top after popping: " << stack.top() << "\n";

		std::cout << "\nPassing container to constructor:"<< "\n";
		std::vector<double> container;
		container.push_back(1.0);
		container.push_back(2.0);

		MutantStack<double, std::vector<double> > stack2(container);
		std::cout << stack2 << "\n";
	}
}

//NOLINTEND(readability-magic-numbers)
