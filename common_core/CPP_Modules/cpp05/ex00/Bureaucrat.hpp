#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	public:
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

		static const int	MAXGRADE = 1;
		static const int	MINGRADE = 150;

		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);


		const std::string	getName(void) const;
		int					getGrade(void) const;

		void				promote(void);
		void				demote(void);

	private:
		const std::string	_name;
		int					_grade;

		Bureaucrat();

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif
