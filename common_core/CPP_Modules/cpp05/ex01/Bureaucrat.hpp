#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "MyException.hpp"
#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
	public:
		//exceptions
		class GradeTooHighException: public MyException {public: GradeTooHighException(const std::string& msg);};
		class GradeTooLowException: public MyException {public: GradeTooLowException(const std::string& msg);};

		//static consts
		static const unsigned char	MAXGRADE = 1;
		static const unsigned char	MINGRADE = 150;

		//constructors
		Bureaucrat(const std::string& name, unsigned char grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);

		//getters
		const std::string	getName(void) const;
		unsigned char		getGrade(void) const;

		//functions
		void				promote(void);
		void				demote(void);
		void				signForm(Form& form) const;

	private:
		const std::string	_name;
		unsigned char		_grade;

		Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif
