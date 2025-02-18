#include "Bureaucrat.hpp"
#include "../colors.hpp"
#include <iostream>
#include <string>
#include <exception>

void test_bureaucrat(const std::string& name, int grade)
{
	std::cout << "Name: " << name << ", Grade: " << grade << "\n";
	try {
		Bureaucrat a(name, grade);
		std::cout << BLUE << a << RESET; 
		Bureaucrat b(a);
		std::cout << "Promote bureaucrat from grade " << b.getGrade() << ":\n";
		b.promote();
		std::cout << BLUE << b << RESET; 
		std::cout << "Demote bureaucrat from grade " << a.getGrade() << ":\n";
		a.demote();
		std::cout << BLUE << a<< RESET; 
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

void test_all_for_bureaucrat(void)
{
	std::cout << BOLD UNDERLINED "TEST: Out of bound at construction\n\n" RESET;
	test_bureaucrat("Duck", Bureaucrat::MAXGRADE - 1);
	test_bureaucrat("Duck", Bureaucrat::MINGRADE + 1);

	std::cout << BOLD UNDERLINED "TEST: Out of bound when increase or decrease grade\n\n" RESET;
	test_bureaucrat("Duck", Bureaucrat::MAXGRADE);
	test_bureaucrat("Duck", Bureaucrat::MINGRADE);

	std::cout << BOLD UNDERLINED "TEST: Normal cases\n\n" RESET;
	test_bureaucrat("Duck", Bureaucrat::MAXGRADE + 1);
	test_bureaucrat("Duck", Bureaucrat::MINGRADE - 1);
	test_bureaucrat("Duck", Bureaucrat::MINGRADE / 2);
}
