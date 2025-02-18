#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>
#include <sstream>

typedef AForm Form;

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other) {(void)other;}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Form* Intern::makeForm(const std::string& name, const std::string& target)
{
	(void)name;
	//throw an exception and print if the name doesn't match any of the forms
	return new RobotomyRequestForm(target);//based on the name return a pointer to the correct form
}
