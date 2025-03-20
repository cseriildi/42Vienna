#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data data;
	data.x = 42;
	std::cout << "Before: " << &data << " " << data.x << "\n";

	uintptr_t s = Serializer::serialize(&data);
	std::cout << "After serialize: " << s << "\n";

	Data *newptr = Serializer::deserialize(s);
	std::cout << "After deserialize: " << newptr << " " << newptr->x << "\n";
}
