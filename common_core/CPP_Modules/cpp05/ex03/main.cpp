#include "AForm.hpp"

void test_all_for_bureaucrat(void);
void test_all_forms(void);
void test_intern(void);


typedef AForm Form;

int main()
{
	test_all_for_bureaucrat();
	test_all_forms();
	test_intern();
}
