#include "RobotomyRequestForm.hpp"
#include <string>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 145, 137, "") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 145, 137, target) {}

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
	if (time(NULL) % 2 == 0)
		std::cout << getTarget() << " has been robotomized\n";
	else {
		std::cout << "Robotomization of " << getTarget() << " failed\n";
		throw AForm::ExecutionFailed("Robotomization failed");
	}
}
