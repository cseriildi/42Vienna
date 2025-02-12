#include "Bureaucrat.hpp"
#include "../colors.hpp"
#include <iostream>
#include <string>
#include <exception>

void test_all(const std::string& name, int grade)
{
	std::cout << "Name: " << name << ", Grade: " << grade << "\n";
	try {
		Bureaucrat a(name, grade);
		std::cout << GREEN << a << RESET; 
		Bureaucrat b(a);
		std::cout << "Promote bureaucrat from grade " << b.getGrade() << ":\n";
		b.promote();
		std::cout << GREEN << b << RESET; 
		std::cout << "Demote bureaucrat from grade " << a.getGrade() << ":\n";
		a.demote();
		std::cout << GREEN << a<< RESET; 
		a = b;
		std::cout <<"Copy assignment:\n" << "a: " << a << "b: " << b << "\n";
		
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << RED << e.what() << RESET " (caught with too high catch)\n\n";
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << RED << e.what() << RESET " (caught with too low catch)\n\n";
	} catch (std::exception &e) {
		std::cout <<  "(caught with general catch)\n\n";
	}
}

int main(void)
{
	std::cout << BOLD UNDERLINED "TEST: Out of bound at construction\n\n" RESET;
	test_all("Duck", 0);
	test_all("Duck", 151);

	std::cout << BOLD UNDERLINED "TEST: Out of bound when increase or decrease grade\n\n" RESET;
	test_all("Duck", 1);
	test_all("Duck", 150);

	std::cout << BOLD UNDERLINED "TEST: Normal cases\n\n" RESET;
	test_all("Duck", 2);
	test_all("Duck", 149);
	test_all("Duck", 100);
}
