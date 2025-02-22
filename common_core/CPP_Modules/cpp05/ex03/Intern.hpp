#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "MyException.hpp"
#include <string>
#include <cstddef>

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
		Intern &operator=(const Intern &other);
		Intern(const Intern &other);

		static Form* makeForm(const std::string& name, const std::string& target);
	
	private:

		static const std::string _forms[3][3];

		static Form* (*const _funcPointers[3])(const std::string& target);
		static Form* createRobotomyRequestForm(const std::string& target);
		static Form* createPresidentialPardonForm(const std::string& target);
		static Form* createShrubberyCreationForm(const std::string& target);

		static size_t identifyForm(const std::string& name);
};

#endif
