#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
	public:

		static const unsigned int GRADETOSIGN = 72;
		static const unsigned int GRADETOEXECUTE = 45;

		RobotomyRequestForm(const std::string& target);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		void execute(const Bureaucrat& executor) const;
		
	private:
		RobotomyRequestForm();
};

#endif
