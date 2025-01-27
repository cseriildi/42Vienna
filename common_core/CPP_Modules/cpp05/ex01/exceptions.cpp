#include "exceptions.hpp"

GradeTooHighException::GradeTooHighException(const std::string& msg) : _msg(msg) {}

GradeTooHighException::~GradeTooHighException() throw() {}

const char* GradeTooHighException::what() const throw()
{
	return _msg.c_str();
}

GradeTooLowException::GradeTooLowException(const std::string& msg) : _msg(msg) {}

GradeTooLowException::~GradeTooLowException() throw() {}

const char* GradeTooLowException::what() const throw()
{
	return _msg.c_str();
}
