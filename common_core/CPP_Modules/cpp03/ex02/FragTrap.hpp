#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap
{
	public:

		FragTrap();
		FragTrap(const std::string& name, unsigned int hitPoints = 100, unsigned int energyPoints = 100, unsigned int attackDamage = 30);
		FragTrap(const FragTrap& other);
		~FragTrap();
		FragTrap&	operator=(const FragTrap& other);

		void	highFivesGuys(void);
};

#endif
