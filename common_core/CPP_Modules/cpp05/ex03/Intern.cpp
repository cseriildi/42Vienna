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

Intern::Intern()
{
	_funcPointers[0] = &Intern::createRobotomyRequestForm;
	_funcPointers[1] = &Intern::createPresidentialPardonForm;
	_funcPointers[2] = &Intern::createShrubberyCreationForm;

}

Intern::~Intern() {}

Intern::Intern(const Intern &other) {(void)other;}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

bool case_ignorant_comp(const char *s1, const char *s2)
{
	size_t i = 0;

	while (s1[i] && s2[i] && std::tolower(s2[i]) == s1[i])
		i++;
	return i == strlen(s1);
}

size_t identify_form(const char* name)
{
	const char *forms[3][3] = {{"robotomy", "request", "form"},
							{"presidential", "pardon", "form"},
							{"shrubbery", "creation", "form"},};

	for (size_t i = 0; i < 3; i++)
	{
		size_t l = 0;
		for (size_t j = 0; j < 3; j++)
		{
			if (not case_ignorant_comp(forms[i][j], name + l))
				break;
			l += strlen(forms[i][j]);
			if (name[l] == '\0')
				return (j == 0) ? UNKNOWN : i;
			if (strchr(" _", name[l]) != NULL)
				l++;
		}
	}
	return UNKNOWN;
} 

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

Form* Intern::makeForm(const std::string& name, const std::string& target) //NOLINT
{
	size_t form_type = identify_form(name.c_str());

	switch (form_type)
	{
		case UNKNOWN:
		{
			std::cout << RED "Form name \"" << name << "\" unknown\n" RESET;
			throw Intern::FormCreationFailed("Couldn't create form.\n");
		}
		default:
		{
			std::cout << "Intern creates " << name << "\n";
			return (this->_funcPointers[form_type])(target);
		}
	}
}

Intern::FormCreationFailed::FormCreationFailed(const std::string& msg): MyException(msg) {}

//NOLINTEND(readability-implicit-bool-conversion, cppcoreguidelines-pro-bounds-pointer-arithmetic, cppcoreguidelines-pro-bounds-constant-array-index, cppcoreguidelines-pro-bounds-array-to-pointer-decay)
