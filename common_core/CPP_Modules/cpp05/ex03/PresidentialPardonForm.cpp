#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", GRADETOSIGN, GRADETOEXECUTE, "") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): 
	AForm("PresidentialPardonForm", GRADETOSIGN, GRADETOEXECUTE, target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}
