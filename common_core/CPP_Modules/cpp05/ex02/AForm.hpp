#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "MyException.hpp"

class Bureaucrat;

class AForm
{
	public:

		class GradeTooHighException: public MyException {public: GradeTooHighException(const std::string& msg);};
		class GradeTooLowException: public MyException {public: GradeTooLowException(const std::string& msg);};
		class FormIsNotSigned: public MyException {public: FormIsNotSigned(const std::string& msg);};

		static const unsigned char	MAXGRADE = 1;
		static const unsigned char	MINGRADE = 150;

		virtual ~AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);

		const std::string	getName(void) const;
		unsigned char		getGradeToSign(void) const;
		unsigned char		getGradeToExecute(void) const;

		void beSigned(const Bureaucrat& bureaucrat);
		void execute(const Bureaucrat& executor) const;

	private:

		const std::string	_name;
		bool				_isSigned;
		const unsigned char	_gradeToSign;
		const unsigned char	_gradeToExecute;

		AForm();
		AForm(const std::string& name, unsigned char gradeToSign, unsigned char gradeToExecute);

};

std::ostream& operator<<(std::ostream& os, const AForm& other);

#endif
