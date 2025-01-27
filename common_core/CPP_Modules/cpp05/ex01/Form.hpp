#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	public:

		static const unsigned char	MAXGRADE = 1;
		static const unsigned char	MINGRADE = 150;

		typedef ::GradeTooHighException GradeTooHighException;
		typedef ::GradeTooLowException GradeTooLowException;

		Form(const std::string& name, unsigned char gradeToSign, unsigned char gradeToExecute);
		~Form();
		Form(const Form &other);
		Form &operator=(const Form &other);

		const std::string	getName(void) const;
		unsigned char		getGradeToSign(void) const;
		unsigned char		getGradeToExecute(void) const;

		void beSigned(const Bureaucrat& bureaucrat);
		void signForm(const Bureaucrat& bureaucrat);

	private:

		const std::string	_name;
		bool				_isSigned;
		const unsigned char	_gradeToSign;
		const unsigned char	_gradeToExecute;

		Form();

};

std::ostream& operator<<(std::ostream& os, const Form& other);

#endif
