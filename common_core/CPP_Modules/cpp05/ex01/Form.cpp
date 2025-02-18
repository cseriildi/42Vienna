#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <sstream>

Form::Form() : _isSigned(false), _gradeToSign(MINGRADE), _gradeToExecute(MAXGRADE) {}

Form::Form(const std::string& name, unsigned int gradeToSign, unsigned int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::ostringstream msg;

	if (gradeToSign > MINGRADE || gradeToExecute > MINGRADE) {
		msg << "Form's grade is too low, it has to be between " \
		<< Form::MAXGRADE << " and " << Form::MINGRADE;
		throw Form::GradeTooLowException(msg.str());
	}
	if (gradeToSign < MAXGRADE || gradeToExecute < MAXGRADE) {
		msg << "Form's grade is too high, it has to be between " \
		<< Form::MAXGRADE << " and " << Form::MINGRADE;
		throw Form::GradeTooHighException(msg.str()); 
	}
}

Form::~Form() {}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned) , _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& other)
{
	os << other.getName() << ", Form grade to sign: " << other.getGradeToSign() \
		<< ", grade to execute: " << other.getGradeToExecute() \
		<< ". The form is " << (other.getStatus() ? "" : "not ") << "signed.\n";
	return os;
}

const std::string& Form::getName(void) const {return _name;}

unsigned int Form::getGradeToSign(void) const {return _gradeToSign;}

unsigned int Form::getGradeToExecute(void) const {return _gradeToExecute;}

bool Form::getStatus(void) const {return _isSigned;}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned) {
		throw Form::FormAlreadySigned("Form is already signed.");
	}
	if (bureaucrat.getGrade() > _gradeToSign) {
		std::ostringstream msg;
		msg << "Bureaucrat's grade (" << bureaucrat.getGrade() \
		<< ") is not sufficient, at least grade " << _gradeToSign << " is required.";
		throw Form::GradeTooLowException(msg.str());
	}
	_isSigned = true;
}

Form::GradeTooHighException::GradeTooHighException(const std::string& msg): MyException(msg) {}

Form::GradeTooLowException::GradeTooLowException(const std::string& msg): MyException(msg) {}

Form::FormAlreadySigned::FormAlreadySigned(const std::string& msg): MyException(msg) {}
