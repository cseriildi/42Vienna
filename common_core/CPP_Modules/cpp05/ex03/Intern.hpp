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

		static const std::string _forms[3][3];

		size_t identifyForm(const std::string& name);

		Form* (Intern::*_funcPointers[3])(const std::string& target);
		Form* createRobotomyRequestForm(const std::string& target);
		Form* createPresidentialPardonForm(const std::string& target);
		Form* createShrubberyCreationForm(const std::string& target);
};

#endif
