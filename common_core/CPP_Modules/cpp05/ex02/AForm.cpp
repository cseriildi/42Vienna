#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

AForm::AForm() : _isSigned(false), _gradeToSign(MINGRADE), _gradeToExecute(MAXGRADE) {}

AForm::AForm(const std::string& name, unsigned char gradeToSign, unsigned char gradeToExecute, const std::string& target) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target)
{
	if (gradeToSign > MINGRADE || gradeToExecute > MINGRADE)
		throw AForm::GradeTooLowException("Grade too low");
	else if (gradeToSign < MAXGRADE || gradeToExecute < MAXGRADE)
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
	os << other.getName() << ", Form grade to sign: " << other.getGradeToSign() << ", grade to execute: " << other.getGradeToExecute() << "\n";
	return os;
}

AForm::GradeTooHighException::GradeTooHighException(const std::string& msg): MyException(msg) {}

AForm::GradeTooLowException::GradeTooLowException(const std::string& msg): MyException(msg) {}

AForm::ExecutionFailed::ExecutionFailed(const std::string& msg): MyException(msg) {}

const std::string AForm::getName(void) const {return _name;}

unsigned char AForm::getGradeToSign(void) const {return _gradeToSign;}

unsigned char AForm::getGradeToExecute(void) const {return _gradeToExecute;}

const std::string AForm::getTarget(void) const {return _target;}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException("Bureaucrat doesn't have the required grade for signing the form!");
	_isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (_isSigned == false) {
		throw AForm::ExecutionFailed("Form is not signed yet!");
	}
	if (executor.getGrade() > _gradeToExecute){
		throw AForm::GradeTooHighException("Bureaucrat doesn't have the required grade for executing the form!");
	}
}

