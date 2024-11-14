#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap
{
	public:

		ScavTrap();
		ScavTrap(const std::string& name,
				unsigned int hitPoints = _hp,
				unsigned int energyPoints = _ep,
				unsigned int attackDamage = _ad);
				
		ScavTrap(const ScavTrap& other);
		~ScavTrap();
		ScavTrap&	operator=(const ScavTrap& other);

		void	attack(const std::string& target);
		void	guardGate();

	protected:

		static const unsigned int	_hp = 100;
		static const unsigned int	_ep = 50;
		static const unsigned int	_ad = 20;
};

#endif
