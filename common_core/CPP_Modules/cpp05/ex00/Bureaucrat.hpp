#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "MyException.hpp"

class Bureaucrat
{
	public:
		//exceptions
		class GradeTooHighException: public MyException {public: GradeTooHighException(const std::string& msg);};
		class GradeTooLowException: public MyException {public: GradeTooLowException(const std::string& msg);};

		//static consts
		static const int	MAXGRADE = 1;
		static const int	MINGRADE = 150;

		//constructors
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);

		//getters
		const std::string	getName(void) const;
		int					getGrade(void) const;

		//functions
		void				promote(void);
		void				demote(void);

	private:
		const std::string	_name;
		int					_grade;

		Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif
