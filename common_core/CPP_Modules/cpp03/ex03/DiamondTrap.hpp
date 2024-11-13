#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:

		DiamondTrap();
		DiamondTrap(const std::string& name, unsigned int hitPoints = 100, unsigned int energyPoints = 50, unsigned int attackDamage = 20);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap();
		DiamondTrap&	operator=(const DiamondTrap& other);

		void	attack(const std::string& target);
		void	whoAmI();
		
	private:

		std::string _name;
};

#endif
