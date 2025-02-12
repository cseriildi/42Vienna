//NOLINTBEGIN(cppcoreguidelines-init-variables)

#include "LinkedList.hpp"

LinkedList g_head = LinkedList(); //NOLINT

void test_subject(void);
void test_materias(void);
void test_characters(void);
void test_materiasources(void);

int main()
{
	test_subject();
	test_materias();
	test_characters();
	test_materiasources();
}
//NOLINTEND(cppcoreguidelines-init-variables)
