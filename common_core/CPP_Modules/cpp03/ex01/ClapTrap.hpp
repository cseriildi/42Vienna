//NOLINTBEGIN(misc-non-private-member-variables-in-classes, cppcoreguidelines-non-private-member-variables-in-classes)

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	public:

		ClapTrap();
		ClapTrap(const std::string& name, unsigned int hitPoints = 10, unsigned int energyPoints = 10, unsigned int attackDamage = 0);
		ClapTrap(const ClapTrap& other);
		virtual ~ClapTrap();
		ClapTrap&	operator=(const ClapTrap& other);

		virtual void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	printInfo();
		
	protected:

		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif

//NOLINTEND(misc-non-private-member-variables-in-classes, cppcoreguidelines-non-private-member-variables-in-classes)
