#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap
{
	public:

		FragTrap();
		FragTrap(const std::string& name,
				unsigned int hitPoints = _hp,
				unsigned int energyPoints = _ep,
				unsigned int attackDamage = _ad);

		FragTrap(const FragTrap& other);
		~FragTrap();
		FragTrap&	operator=(const FragTrap& other);

		void	highFivesGuys(void);

	protected:

		static const unsigned int	_hp = 100;
		static const unsigned int	_ep = 100;
		static const unsigned int	_ad = 30;
		
};

#endif
