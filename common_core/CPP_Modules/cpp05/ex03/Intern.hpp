#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

typedef AForm Form;

class Intern
{
	public:

		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);

		static Form* makeForm(const std::string& name, const std::string& target);

};

#endif
