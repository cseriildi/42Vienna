#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <string>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", GRADETOSIGN, GRADETOEXECUTE, "")
{
	srand(clock());
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("RobotomyRequestForm", GRADETOSIGN, GRADETOEXECUTE, target)
{
	srand(clock());
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << "Brrrrrrrr!\n";
	if (rand() % 2 == 0)
		std::cout << getTarget() << " has been robotomized\n";
	else {
		std::cout << "Robotomization of " << getTarget() << " failed\n";
		throw AForm::ExecutionFailed("Robotomization failed");
	}
}

