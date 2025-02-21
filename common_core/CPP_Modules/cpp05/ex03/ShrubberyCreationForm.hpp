#ifndef SHRUBBERYCREATIONFROM_HPP
#define SHRUBBERYCREATIONFROM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
	public:
		
		static const unsigned int GRADETOSIGN = 145;
		static const unsigned int GRADETOEXECUTE = 137;

		ShrubberyCreationForm(const std::string& target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		void execute(const Bureaucrat& executor) const;
		
	private:
		ShrubberyCreationForm();
};

#define TREE \
		"**************************************************************\n" \
        "**************************************************************\n" \
        "**                                                          **\n" \
		"**       *                                                  **\n" \
		"**      ***                                                 **\n" \
		"**     *****                  **                   *        **\n" \
		"**       *                  ******                ***       **\n" \
		"**                        **********             *****      **\n" \
		"**                      **************          *******     **\n" \
		"**                    ******************       *********    **\n" \
		"**                        **********               *        **\n" \
		"**                      **************                      **\n" \
		"**                    ******************                    **\n" \
		"**                  **********************                  **\n" \
		"**                **************************                **\n" \
		"**                    ******************                    **\n" \
		"**                  **********************                  **\n" \
		"**                **************************                **\n" \
		"**              ******************************              **\n" \
		"**            **********************************            **\n" \
		"**                **************************                **\n" \
		"**              ******************************              **\n" \
		"**            **********************************            **\n" \
		"**          **************************************          **\n" \
		"**        ******************************************        **\n" \
		"**                          ******                          **\n" \
		"**                          ******                          **\n" \
		"**                          ******                          **\n" \
		"**                                                          **\n" \
		"**                                                          **\n" \
		"**                                                          **\n" \
		"**************************************************************\n" \
		"**************************************************************\n"

#endif
