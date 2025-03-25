//NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers, cppcoreguidelines-pro-bounds-array-to-pointer-decay)

#include "iter.hpp"
#include <cctype>
#include <cmath>

void sqrt2(int *i)
{
	*i = static_cast<int>(std::sqrt(*i));
}

void upper(char *c)
{
	*c = static_cast<char>(std::toupper(*c));
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
//NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers, cppcoreguidelines-pro-bounds-array-to-pointer-decay)
