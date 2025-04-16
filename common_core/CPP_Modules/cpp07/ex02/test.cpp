//NOLINTBEGIN
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include "Array.hpp"
#include "../colors.hpp"

#define MAX_VAL 750

int test_from_subject(void)
{
	std::cout << BOLD UNDERLINED "Test from subject\n" RESET;

	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
	return 0;
}

void test_array(void)
{
	std::cout << BOLD UNDERLINED "\nTest empty (default constructed) array\n" RESET;

	Array<char> empty_arr = Array<char>();
	std::cout << "Size: " << empty_arr.size() << "\n";
	std::cout << "Array: " << empty_arr << "\n";

	std::cout << BOLD UNDERLINED "Test copy constructer\n" RESET;

	Array<int> arr(5);
	std::cout << "Size: " << arr.size() << "\n";
	std::cout << "Array after construction:\n" << arr;

	for (size_t i = 0; i < arr.size(); ++i)
		arr[i] = i;

	std::cout << "Array after changing the elements:\n" << arr;

	Array<int> arr2(arr);
	std::cout << "Copy constructed array:\n" << arr2;
	for (size_t i = 0; i < arr2.size(); ++i)
		arr2[i] = i * 2;

	std::cout << "Copy constructed array after changing elements:\n" << arr2;
	std::cout << "Original array:\n" << arr;

	std::cout << BOLD UNDERLINED "\nTest assignment operator\n" RESET;

	std::cout << "Original array:\n" << arr;
	arr2 = arr;
	std::cout << "Copy assigned array:\n" << arr2;
	for (size_t i = 0; i < arr2.size(); ++i)
		arr2[i] = i * 3;
	std::cout << "Copy assigned array after changing elements:\n" << arr2;
	std::cout << "Original array:\n" << arr;

	std::cout << BOLD UNDERLINED "\nTest out of bounds\n" RESET;
	try {
		std::cout << arr[arr.size()] << "\n";
	} catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	std::cout << BOLD UNDERLINED "\nTest const array\n" RESET;
	const Array<int> const_arr(arr);
	std::cout << "Size: " << const_arr.size() << "\n";
	std::cout << "Copy constructed const array:\n" << const_arr;
	std::cout << "First element of const array: " << const_arr[0] << "\n";
	/* for (size_t i = 0; i < const_arr.size(); ++i)
		const_arr[i] = 2; */

	//const_arr = arr;
	arr = const_arr; //copy assigning from const array to non-const array
	Array<int> arr3(const_arr); //copy constructing from const array to non-const array
}

//NOLINTEND
