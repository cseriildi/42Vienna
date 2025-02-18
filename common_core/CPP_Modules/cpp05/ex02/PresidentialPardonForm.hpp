#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	public:

		static const unsigned int GRADETOSIGN = 25;
		static const unsigned int GRADETOEXECUTE = 5;

		PresidentialPardonForm(const std::string& target);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

		void execute(const Bureaucrat& executor) const;
		
	private:
		PresidentialPardonForm();
};

#endif
