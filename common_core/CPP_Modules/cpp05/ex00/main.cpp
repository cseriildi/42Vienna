#include "Bureaucrat.hpp"

void test_all(const std::string& name, int grade)
{
	std::cout << "Name: " << name << ", Grade: " << grade << "\n";
	try {
		Bureaucrat a(name, grade);
		std::cout << "\033[0;34m" << a << "\033[0m"; 
		Bureaucrat b(a);
		std::cout << "Promote bureaucrat from grade " << b.getGrade() << ":\n";
		b.promote();
		std::cout << "\033[0;34m" << b << "\033[0m"; 
		std::cout << "Demote bureaucrat from grade " << a.getGrade() << ":\n";
		a.demote();
		std::cout << "\033[0;34m" << a<< "\033[0m"; 
		a = b;
		std::cout <<"Copy assignment:\n" << "a: " << a << "b: " << b << "\n";
		
	} catch (std::exception &e) {
		std::cout << "\033[0;31m" << e.what() << "\033[0m \n\n";
	}
}


int main()
{
	std::cout << "\033[1;30mTEST: Out of bound at construction\033[0m\n\n";
	test_all("Duck", 0);
	test_all("Duck", 151);

	std::cout << "\033[1;30mTEST: Out of bound when increase or decrease grade\033[0m\n\n";
	test_all("Duck", 1);
	test_all("Duck", 150);

	std::cout << "\033[1;30mTEST: Normal cases\033[0m\n\n";
	test_all("Duck", 2);
	test_all("Duck", 149);
	test_all("Duck", 100);
}
