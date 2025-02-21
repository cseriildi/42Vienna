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
		class FormAlreadySigned: public MyException {public: FormAlreadySigned(const std::string& msg);};

		//static consts
		static const unsigned int	MAXGRADE = Bureaucrat::MAXGRADE;
		static const unsigned int	MINGRADE = Bureaucrat::MINGRADE;

		//constructors
		Form(const std::string& name, unsigned int gradeToSign, unsigned int gradeToExecute);
		~Form();
		Form(const Form &other);
		Form &operator=(const Form &other);

		//getters
		const std::string&	getName(void) const;
		unsigned int		getGradeToSign(void) const;
		unsigned int		getGradeToExecute(void) const;
		bool				getStatus(void) const;

		//functions
		void beSigned(const Bureaucrat& bureaucrat);

	private:

		const std::string	_name; 				//NOLINT
		bool				_isSigned; 			//NOLINT
		const unsigned int	_gradeToSign;		//NOLINT
		const unsigned int	_gradeToExecute;	//NOLINT

		Form();
};

std::ostream& operator<<(std::ostream& os, const Form& other);

#endif
