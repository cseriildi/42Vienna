#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class MyException;

class Form
{
	public:
		//exceptions
		class GradeTooHighException: public MyException {public: GradeTooHighException(const std::string& msg);};
		class GradeTooLowException: public MyException {public: GradeTooLowException(const std::string& msg);};

		//static consts
		static const unsigned char	MAXGRADE = 1;
		static const unsigned char	MINGRADE = 150;

		//constructors
		Form(const std::string& name, unsigned char gradeToSign, unsigned char gradeToExecute);
		~Form();
		Form(const Form &other);
		Form &operator=(const Form &other);

		//getters
		const std::string&	getName(void) const;
		unsigned char		getGradeToSign(void) const;
		unsigned char		getGradeToExecute(void) const;

		//functions
		void beSigned(const Bureaucrat& bureaucrat);

	private:

		const std::string	_name; //NOLINT
		bool				_isSigned; //NOLINT
		const unsigned char	_gradeToSign; //NOLINT
		const unsigned char	_gradeToExecute; //NOLINT

		Form();
};

std::ostream& operator<<(std::ostream& os, const Form& other);

#endif
