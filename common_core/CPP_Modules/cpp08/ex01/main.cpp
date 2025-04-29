#include "Span.hpp"
#include "../colors.hpp"
#include <iostream>

int main(void)
{
	{
		std::cout << UNDERLINED BOLD "Test from subject\n" RESET;
		//NOLINTBEGIN

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		return 0;
		//NOLINTEND
	}
}
