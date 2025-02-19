#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "../colors.hpp"
#include <iostream>
#include <string>
#include <exception>

typedef AForm Form;

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
	std::cout << BOLD UNDERLINED "\nTEST: Presidential Pardon Form\n\n" RESET;

	PresidentialPardonForm ppf("Kamilla");
	std::cout << ppf << "\n";
	test_form(&ppf);

	std::cout << BOLD UNDERLINED "\nTEST: Robotomy Request Form\n\n" RESET;

	RobotomyRequestForm rrf("Lukas");
	std::cout << rrf << "\n";
	test_form(&rrf);

	std::cout << BOLD UNDERLINED "\nTEST: Shrubbery Creation Form\n\n" RESET;

	ShrubberyCreationForm scf("Lea");
	std::cout << scf << "\n";
	test_form(&scf);
}

void test_form_creation(const std::string& name, const std::string& target)
{
	try {
		Intern me = Intern();
		Form *form = me.makeForm(name, target); //NOLINT
		std::cout << *form;
		delete form;
	
	} catch (Intern::FormCreationFailed &e) {
		std::cout << RED << e.what() << RESET;
	}
}

void test_intern(void)
{
	std::cout << BOLD UNDERLINED "\nTEST: Intern, Presidential Pardon Form\n\n" RESET;
	test_form_creation("Presidential Pardon Form", "test1");
	test_form_creation("Presidential Pardon Form form", "test2");
	test_form_creation("presidential pardon", "test3");
	test_form_creation("PreSidential_PardOn form", "test4");
	test_form_creation("Presidential", "test5");

	std::cout << BOLD UNDERLINED "\nTEST: Intern, Robotomy Request Form\n\n" RESET;
	test_form_creation("Robotomy Request Form", "test1");
	test_form_creation("robotomy request Form form", "test2");
	test_form_creation("roboTomy requeSt", "test3");
	test_form_creation("robotomy", "test4");

	std::cout << BOLD UNDERLINED "\nTEST: Intern, Shrubbery Creation Form\n\n" RESET;
	test_form_creation("Shrubbery Creation Form", "test1");
	test_form_creation("shrubbery creation Form form", "test2");
	test_form_creation("shrubberY_CREATION", "test3");
	test_form_creation("shrubbery", "test4");

	std::cout << BOLD UNDERLINED "\nTEST: Intern, random forms\n\n" RESET;
	test_form_creation("", "test1");
	test_form_creation(" ", "test2");
	test_form_creation("hgfghfdg", "test3");
	test_form_creation("form", "test4");
	test_form_creation("pardon", "test5");
	test_form_creation("creation", "test6");
	test_form_creation("request", "test7");
	test_form_creation("éáő őp", "test7");
	test_form_creation("🦆", "test7");
}
//NOLINTBEGIN
void test_from_subject(void)
{
	std::cout << BOLD UNDERLINED "\nTEST FROM SUBJECT\n\n" RESET;

	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	std::cout << *rrf;
	delete rrf;
}
//NOLINTEND
