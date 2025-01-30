#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat() : _grade(MINGRADE) {}

Bureaucrat::Bureaucrat(const std::string& name, unsigned char grade) : _name(name), _grade(grade)
{
	if (grade > MINGRADE)
		throw GradeTooLowException("Grade too low");
	else if (grade < MAXGRADE)
		throw GradeTooHighException("Grade too high");
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << "\n";
	return os;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg): MyException(msg) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg): MyException(msg) {}

const std::string Bureaucrat::getName(void) const {return _name;}

unsigned char Bureaucrat::getGrade(void) const {return _grade;}

void Bureaucrat::promote(void)
{
	if (_grade == MAXGRADE)
		throw GradeTooHighException("Grade too high");
	_grade--;
}

void Bureaucrat::demote(void)
{
	if (_grade == MINGRADE)
		throw GradeTooLowException("Grade too low");
	_grade++;
}

void Bureaucrat::signForm(AForm& form)
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << "\n";
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << "\n";
	}
}

void Bureaucrat::executeForm(const AForm& form)
{
	try {
		form.execute(*this);
		std::cout <<  _name << " executed " << form.getName() << "\n";
	} catch (AForm::ExecutionFailed &e) {
		std::cout <<  _name << " couldn’t execute " << form.getName() << " because " << e.what() << "\n";
	} catch (AForm::GradeTooLowException &e) { 
		std::cout <<  _name << " couldn’t execute " << form.getName() << " because " << e.what() << "\n";
	}
}
