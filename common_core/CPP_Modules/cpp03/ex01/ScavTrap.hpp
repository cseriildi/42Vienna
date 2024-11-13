#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
	public:

		ScavTrap();
		ScavTrap(const std::string& name, unsigned int hitPoints = 100, unsigned int energyPoints = 50, unsigned int attackDamage = 20);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();
		ScavTrap&	operator=(const ScavTrap& other);

		void	attack(const std::string& target);

		void guardGate();
		
	private:
};

#endif
