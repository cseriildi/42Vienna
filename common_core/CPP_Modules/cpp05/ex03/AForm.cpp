#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "MyException.hpp"
#include <string>
#include <iostream>
#include <sstream>

AForm::AForm() : _isSigned(false), _gradeToSign(MINGRADE), _gradeToExecute(MAXGRADE) {}

AForm::AForm(const std::string& name, unsigned int gradeToSign, unsigned int gradeToExecute, const std::string& target) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target)
{
	if (gradeToSign > MINGRADE || gradeToExecute > MINGRADE)
		throw AForm::GradeTooLowException("Grade too low");
	if (gradeToSign < MAXGRADE || gradeToExecute < MAXGRADE)
		throw AForm::GradeTooHighException("Grade too high");
}

AForm::~AForm() {}

AForm::AForm(const AForm &other) :
	_name(other._name), _isSigned(other._isSigned) , _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _target(other._target) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& other)
{
	os << other.getName() << ", Form grade to sign: " << other.getGradeToSign() \
		<< ", grade to execute: " << other.getGradeToExecute() << ", target: "<< other.getTarget()\
		<< ". The form is " << (other.getStatus() ? "" : "not ") << "signed.\n";
	return os;
}

AForm::GradeTooHighException::GradeTooHighException(const std::string& msg): MyException(msg) {}

AForm::GradeTooLowException::GradeTooLowException(const std::string& msg): MyException(msg) {}

AForm::FormAlreadySigned::FormAlreadySigned(const std::string& msg): MyException(msg) {}

AForm::ExecutionFailed::ExecutionFailed(const std::string& msg): MyException(msg) {}

bool AForm::getStatus(void) const {return _isSigned;}

const std::string& AForm::getName(void) const {return _name;}

unsigned int AForm::getGradeToSign(void) const {return _gradeToSign;}

unsigned int AForm::getGradeToExecute(void) const {return _gradeToExecute;}

const std::string& AForm::getTarget(void) const {return _target;}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned) {
		throw AForm::FormAlreadySigned("Form is already signed.");
	}
	if (bureaucrat.getGrade() > _gradeToSign) {
		std::ostringstream msg;
		msg << "Bureaucrat's grade (" << bureaucrat.getGrade() \
		<< ") is not sufficient, at least grade " << _gradeToSign << " is required.";
		throw AForm::GradeTooLowException(msg.str());
	}
	_isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (not _isSigned) {
		throw AForm::ExecutionFailed("Form is not signed yet!");
	}
	if (executor.getGrade() > _gradeToExecute){
		std::ostringstream msg;
		msg << "Bureaucrat's grade (" << executor.getGrade() \
		<< ") is not sufficient, at least grade " << _gradeToExecute << " is required.";
		throw AForm::GradeTooLowException(msg.str());
	}
}

