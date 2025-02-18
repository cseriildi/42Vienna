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
		class FormAlreadySigned: public MyException {public: FormAlreadySigned(const std::string& msg);};
		class ExecutionFailed: public MyException {public: ExecutionFailed(const std::string& msg);};

		static const unsigned int	MAXGRADE = 1;
		static const unsigned int	MINGRADE = 150;

		virtual ~AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);

		const std::string&	getName(void) const;
		unsigned int		getGradeToSign(void) const;
		unsigned int		getGradeToExecute(void) const;
		const std::string&	getTarget(void) const;
		bool				getStatus(void) const;

		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(const Bureaucrat& executor) const;

	protected:

		AForm(const std::string& name, unsigned int gradeToSign, unsigned int gradeToExecute, const std::string& target);
	
	private:

		const std::string	_name;				//NOLINT
		bool				_isSigned;			//NOLINT
		const unsigned int	_gradeToSign;		//NOLINT
		const unsigned int	_gradeToExecute;	//NOLINT
		const std::string	_target;			//NOLINT

		AForm();
};

std::ostream& operator<<(std::ostream& os, const AForm& other);

#endif
