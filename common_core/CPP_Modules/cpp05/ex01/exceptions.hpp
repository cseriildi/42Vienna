#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>
#include <exception>

class GradeTooHighException : public std::exception
{
	public:
		GradeTooHighException(const std::string& msg);
		~GradeTooHighException() throw();
		const char* what() const throw();

	private:
		std::string _msg;
};

class GradeTooLowException : public std::exception
{
	public:
		GradeTooLowException(const std::string& msg);
		~GradeTooLowException() throw();
		const char* what() const throw();

	private:
		std::string _msg;
};

#endif
