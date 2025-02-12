#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

Form::Form() : _isSigned(false), _gradeToSign(MINGRADE), _gradeToExecute(MAXGRADE) {}

Form::Form(const std::string& name, unsigned char gradeToSign, unsigned char gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > MINGRADE || gradeToExecute > MINGRADE)
		throw Form::GradeTooLowException("Grade too low");
	if (gradeToSign < MAXGRADE || gradeToExecute < MAXGRADE)
		throw Form::GradeTooHighException("Grade too high");
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
	os << other.getName() << ", Form grade to sign: " << other.getGradeToSign() << ", grade to execute: " << other.getGradeToExecute() << "\n";
	return os;
}

const std::string& Form::getName(void) const {return _name;}

unsigned char Form::getGradeToSign(void) const {return _gradeToSign;}

unsigned char Form::getGradeToExecute(void) const {return _gradeToExecute;}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException("Bureaucrat doesn't have the required grade for signing the form!");
	_isSigned = true;
}

Form::GradeTooHighException::GradeTooHighException(const std::string& msg): MyException(msg) {}

Form::GradeTooLowException::GradeTooLowException(const std::string& msg): MyException(msg) {}
