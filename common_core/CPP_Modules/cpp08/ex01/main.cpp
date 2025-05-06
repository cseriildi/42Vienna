//NOLINTBEGIN(misc-use-internal-linkage)
#include <cstdlib>
#include <ctime>

void test_from_subject(void);
void test_addNumber(void);
void test_addNumbers(void);
void test_shortestLongestSpan(void);

int main(void)
{
	std::srand(std::time(0));

	test_from_subject();
	test_addNumber();
	test_addNumbers();
	test_shortestLongestSpan();
}
//NOLINTEND(misc-use-internal-linkage)
