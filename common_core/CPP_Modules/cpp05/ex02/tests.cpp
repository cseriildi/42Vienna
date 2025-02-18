#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
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

void test_form(AForm *form)
{
	Bureaucrat signer("Duck", form->getGradeToSign());
	Bureaucrat executer("Ducky", form->getGradeToExecute());

	if (form->getGradeToSign() < Bureaucrat::MINGRADE)
	{
		Bureaucrat bob("Bob", form->getGradeToSign() + 1);
		bob.signForm(*form);
	}

	executer.executeForm(*form);
	
	if (form->getGradeToExecute() < Bureaucrat::MINGRADE)
	{
		Bureaucrat anna("Anna", form->getGradeToExecute() + 1);
		anna.executeForm(*form);
		signer.signForm(*form);
		anna.executeForm(*form);
	}
	signer.signForm(*form);
	executer.executeForm(*form);
	executer.executeForm(*form);
	executer.executeForm(*form);
	executer.executeForm(*form);
}

void test_all_forms(void)
{
	std::cout << BOLD UNDERLINED "TEST: Presidential Pardon Form\n\n" RESET;

	PresidentialPardonForm ppf("Kamilla");
	std::cout << ppf << "\n";
	test_form(&ppf);

	std::cout << BOLD UNDERLINED "TEST: Robotomy Request Form\n\n" RESET;

	RobotomyRequestForm rrf("Lukas");
	std::cout << rrf << "\n";
	test_form(&rrf);

	std::cout << BOLD UNDERLINED "TEST: Shrubbery Creation Form\n\n" RESET;

	ShrubberyCreationForm scf("Lea");
	std::cout << scf << "\n";
	test_form(&scf);
}
