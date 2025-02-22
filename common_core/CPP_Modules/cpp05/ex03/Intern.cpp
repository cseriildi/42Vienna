//NOLINTBEGIN(readability-implicit-bool-conversion, cppcoreguidelines-pro-bounds-pointer-arithmetic, cppcoreguidelines-pro-bounds-constant-array-index, cppcoreguidelines-pro-bounds-array-to-pointer-decay)

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "MyException.hpp"
#include "../colors.hpp"
#include <cstring>
#include <string>
#include <iostream>
#include <cstddef>
#include <cctype>

typedef AForm Form;

const std::string Intern::_forms[3][3] = {
    {"robotomy", "request", "form"},
    {"presidential", "pardon", "form"},
    {"shrubbery", "creation", "form"}
};

Form* (*const Intern::_funcPointers[3])(const std::string&) = {
	Intern::createRobotomyRequestForm,
	Intern::createPresidentialPardonForm,
	Intern::createShrubberyCreationForm
};

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other) {(void)other;} //NOLINT

Intern &Intern::operator=(const Intern &other)  //NOLINT
{
	(void)other;
	return *this;
}

bool case_ignorant_comp(const std::string& s1, const std::string& s2)
{
	if (s1.size() != s2.size())
		return false;
	
	for (size_t i = 0; i < s1.size(); ++i)
	{
		if (std::tolower(s1[i]) != std::tolower(s2[i]))
            return false;
    }
    return true;
}

size_t Intern::identifyForm(const std::string& name)
{
	for (size_t i = 0; i < 3; i++)
	{
		size_t l = 0;
		for (size_t j = 0; j < 3; j++)
		{
			if (!case_ignorant_comp(_forms[i][j], name.substr(l, _forms[i][j].size())))
				break;
			l += _forms[i][j].size();
			if (l == name.size())
				return (j == 0) ? UNKNOWN : i;
			l += (name[l] == ' ' || name[l] == '_');
		}
	}
	return UNKNOWN;
} 

Form* Intern::createRobotomyRequestForm(const std::string& target) {return new RobotomyRequestForm(target);}

Form* Intern::createPresidentialPardonForm(const std::string& target) {return new PresidentialPardonForm(target);}

Form* Intern::createShrubberyCreationForm(const std::string& target) {return new ShrubberyCreationForm(target);}

Form* Intern::makeForm(const std::string& name, const std::string& target) //NOLINT
{
	size_t form_id = identifyForm(name);

	if (form_id == UNKNOWN) {
		std::cout << RED "Form " << name << " is unknown\n" RESET;
		throw Intern::FormCreationFailed("Couldn't create form.\n");
	}
	std::cout << "Intern creates " << name << "\n";
	return (_funcPointers[identifyForm(name)])(target);;
}

Intern::FormCreationFailed::FormCreationFailed(const std::string& msg): MyException(msg) {}

//NOLINTEND(readability-implicit-bool-conversion, cppcoreguidelines-pro-bounds-pointer-arithmetic, cppcoreguidelines-pro-bounds-constant-array-index, cppcoreguidelines-pro-bounds-array-to-pointer-decay)
