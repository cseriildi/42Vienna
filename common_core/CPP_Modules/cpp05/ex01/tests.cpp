#include "Bureaucrat.hpp"
#include "Form.hpp"
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

void test_form(const std::string& name, unsigned int gradeToSign, unsigned int gradeToExecute)
{
	std::cout << "Name: " << name << ", Grade to sign: " << gradeToSign \
			<<", Grade to execute: " << gradeToExecute << "\n";
	try {
		Form a(name, gradeToSign, gradeToExecute);
		std::cout << BLUE << a << RESET; 
		Form b(a);
		
		if (gradeToSign < Bureaucrat::MINGRADE)
		{
			Bureaucrat Karen("Karen", gradeToSign + 1);
			Karen.signForm(a);
		}
		Bureaucrat Bob("Bob", gradeToSign);
		Bob.signForm(a);
		Bob.signForm(a);

		std::cout <<"Before copy assignment:\n" << "a: " << a << "b: " << b << "\n";
		a = b;
		std::cout <<"After copy assignment:\n" << "a: " << a << "b: " << b << "\n";
		
	} catch (Form::GradeTooHighException &e) {
		std::cout << RED << e.what() << RESET " (caught with too high catch)\n\n";
	} catch (Form::GradeTooLowException &e) {
		std::cout << RED << e.what() << RESET " (caught with too low catch)\n\n";
	} catch (std::exception &e) {
		std::cout <<  "(caught with general catch)\n\n";
	}
}

void test_all_for_form(void)
{
	std::cout << BOLD UNDERLINED "TEST: Out of bound at construction\n\n" RESET;
	test_form("Form1", Form::MAXGRADE - 1, Form::MAXGRADE);
	test_form("Form2", Form::MINGRADE + 1, Form::MINGRADE);
	test_form("Form3", Form::MAXGRADE, Form::MAXGRADE - 1);
	test_form("Form4", Form::MINGRADE, Form::MINGRADE + 1);

	std::cout << BOLD UNDERLINED "TEST: Normal cases\n\n" RESET;
	test_form("Form5", Form::MAXGRADE, Form::MINGRADE);
	test_form("Form6", Form::MINGRADE, Form::MAXGRADE);
	test_form("Form7", Form::MINGRADE / 2, Form::MINGRADE / 2);
}
