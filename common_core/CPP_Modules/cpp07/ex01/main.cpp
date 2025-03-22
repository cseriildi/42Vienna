#include "iter.hpp"
#include <cmath>

void sqrt2(int *i)
{
	*i = std::sqrt(*i);
}

void upper(char *c)
{
	*c = std::toupper(*c);
}

int main(void)
{
	int arr1[] = {42, 56, 71, 102};
	char arr2[] = "Hello";

	::iter(arr1, 4, display); //::iter(arr1, 4, display<int>);
	::iter(arr1, 4, sqrt2);
	::iter(arr1, 4, display);

	::iter(arr2, 5, display);
	::iter(arr2, 5, upper);
	::iter(arr2, 5, display);

}
