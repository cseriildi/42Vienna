#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat() : _grade(MINGRADE) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade < MINGRADE)
	{
		//exception

	}
	else if (grade > MAXGRADE)
	{

		//exception
	}
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {}

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

const std::string Bureaucrat::getName(void) const {return _name;}

int Bureaucrat::getGrade(void) const {return _grade;}

void Bureaucrat::incrementGrade(void)
{
	if (_grade == MAXGRADE)
		//exception
	_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade == MINGRADE)
		//exception
	_grade++;
}

