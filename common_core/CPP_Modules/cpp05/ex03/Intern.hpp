#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "MyException.hpp"
#include <string>

typedef AForm Form;

enum Forms
{
    ROBOTOMY,
	PRESIDENTIAL,
	SHRUBBERY,
	UNKNOWN
};

class Intern
{
	public:

		class FormCreationFailed: public MyException {public: FormCreationFailed(const std::string& msg);};

		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);

		Form* makeForm(const std::string& name, const std::string& target);

	private:
		AForm* (Intern::*_funcPointers[3])();

		AForm* createRobotomyRequestForm(const std::string& target);
		AForm* createPresidentialPardonForm(const std::string& target);
		AForm* createShrubberyCreationForm(const std::string& target);

};

#endif
