#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "MyException.hpp"

class AForm;

class Bureaucrat
{
	public:
		class GradeTooHighException: public MyException {public: GradeTooHighException(const std::string& msg);};
		class GradeTooLowException: public MyException {public: GradeTooLowException(const std::string& msg);};

		static const unsigned char	MAXGRADE = 1;
		static const unsigned char	MINGRADE = 150;

		Bureaucrat(const std::string& name, unsigned char grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);

		const std::string	getName(void) const;
		unsigned char		getGrade(void) const;

		void				promote(void);
		void				demote(void);
		void				signForm(AForm& form);
		void				executeForm(const AForm& form);

	private:
		const std::string	_name;
		unsigned char		_grade;

		Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif
