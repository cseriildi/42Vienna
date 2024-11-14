#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:

		DiamondTrap();
		DiamondTrap(const std::string& name,
				unsigned int hitPoints = FragTrap::_hp,
				unsigned int energyPoints = ScavTrap::_ep,
				unsigned int attackDamage = FragTrap::_ad);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap();
		DiamondTrap&	operator=(const DiamondTrap& other);

		void	whoAmI();
		
	private:

		std::string _name;
};

#endif
