#include "Bureaucrat.hpp"
#include "MyException.hpp"
#include <string>
#include <iostream>
#include <sstream>

Bureaucrat::Bureaucrat() : _grade(MINGRADE) {}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name), _grade(grade)
{
	std::ostringstream msg;

	if (grade > MINGRADE) {
		msg << "Bureaucrat's grade (" << grade << ") is too low, it has to be between " \
		<< Bureaucrat::MAXGRADE << " and " << Bureaucrat::MINGRADE;
		throw Bureaucrat::GradeTooLowException(msg.str());
	}
	if (grade < MAXGRADE) {
		msg << "Bureaucrat's grade (" << grade << ") is too high, it has to be between " \
		<< Bureaucrat::MAXGRADE << " and " << Bureaucrat::MINGRADE;
		throw Bureaucrat::GradeTooHighException(msg.str());
	}
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

const std::string& Bureaucrat::getName(void) const {return _name;}

unsigned int Bureaucrat::getGrade(void) const {return _grade;}

void Bureaucrat::promote(void)
{
	if (_grade == MAXGRADE)
		throw Bureaucrat::GradeTooHighException("Bureaucrat can't be promoted");
	_grade--;
}

void Bureaucrat::demote(void)
{
	if (_grade == MINGRADE)
		throw Bureaucrat::GradeTooLowException("Bureaucrat can't be demoted");
	_grade++;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg): MyException(msg) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg): MyException(msg) {}
