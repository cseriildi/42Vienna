#include "utils.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <clocale>

int		main(void)
{
	PhoneBook		my_phonebook;
	std::wstring	input;

	input.reserve(10); //to avoid invalid read, because of std::basic_string is dinamically allocated, initially started with a very small size
	setlocale(LC_CTYPE, "");
	while (true)
	{
		std::wcout << "Enter a command (ADD/SEARCH/EXIT): ";
		std::getline(std::wcin, input);
		if (std::wcin.eof())
			reopen_stdin();
		else if (input == L"ADD")
			my_phonebook.add_contact();
		else if (input == L"SEARCH")
			my_phonebook.search_contact();
		else if (input == L"EXIT")
			break;
	}
}
