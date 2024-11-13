//NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap a = ClapTrap();
   	ClapTrap b = ClapTrap("Duck");
	ScavTrap c = ScavTrap();
	ScavTrap d = ScavTrap("Duck2");

	d.attack("Goose");
	d.printInfo();
	d.takeDamage(2);
    d.printInfo();
	d.guardGate();
	d.printInfo();
	d.beRepaired(420);
	d.printInfo();
	d.takeDamage(42);
	d.printInfo();
	d.takeDamage(420);
	d.printInfo();
	d.takeDamage(420);
	d.printInfo();
	d.attack("Goose");
	d.printInfo();
	d.beRepaired(42);
	d.printInfo();
	d.attack("Goose");
	d.printInfo();
	d.guardGate();
	d.printInfo();
    return 0;
}

//NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
