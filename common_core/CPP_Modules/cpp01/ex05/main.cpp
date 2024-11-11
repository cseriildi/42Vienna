# include "Harl.hpp"

int	main()
{
	Harl myHarl;

	myHarl.complain("DEBUG");
	myHarl.complain("INFO");
	myHarl.complain("WARNING");
	myHarl.complain("ERROR");
	myHarl.complain("whatever");
	
	return 0;
}
