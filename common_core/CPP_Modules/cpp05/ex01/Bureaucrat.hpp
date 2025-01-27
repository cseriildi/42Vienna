#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "exceptions.hpp"

class Bureaucrat
{
	public:

		static const unsigned char	MAXGRADE = 1;
		static const unsigned char	MINGRADE = 150;

		typedef ::GradeTooHighException GradeTooHighException;
		typedef ::GradeTooLowException GradeTooLowException;

		Bureaucrat(const std::string& name, unsigned char grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);


		const std::string	getName(void) const;
		unsigned char		getGrade(void) const;

		void				promote(void);
		void				demote(void);

	private:
		const std::string	_name;
		unsigned char		_grade;

		Bureaucrat();

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif
