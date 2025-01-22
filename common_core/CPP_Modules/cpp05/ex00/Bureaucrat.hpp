#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
	public:
		static const int	MAXGRADE = 1;
		static const int	MINGRADE = 150;

		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);


		const std::string	getName(void) const;
		int					getGrade(void) const;

		void				incrementGrade(void);
		void				decrementGrade(void);

	private:
		const std::string	_name;
		int					_grade;

		Bureaucrat();

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif
