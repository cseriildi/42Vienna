//NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

#include "utils.hpp"
#include <string>
#include <cstdio>
#include <iostream>
#include <cctype>
#include <sstream>
#include <iomanip>

void	reopen_stdin()
{
	if (std::wcin.eof())
	{
		std::wcin.clear();
		std::wcin.ignore(0, '\n');
		std::freopen("/dev/tty", "r", stdin);
		std::wcout << "\n";
	}
}

std::wstring get_data(const std::wstring& field)
{
	std::wstring data;

	while (true)
	{
		std::wcout << "Enter " << field << ": ";
		std::getline(std::wcin, data);
		if (std::wcin.eof())
		{
			reopen_stdin();
			std::cerr << "This field cannot be empty!\n";
			continue;
		}
		if (has_emoji(data))
		{
			std::cerr << "Emoji is not allowed!\n";
			continue;
		}
		data = trim(data);
		if (data.empty())
		{
			std::cerr << "This field cannot be empty!\n";
			continue;
		}
		if (field == L"Phone Number" && !valid_phone_number(data))
		{
			std::cerr << "Phone number is not valid!\n";
			continue;
		}
		break;
	}
	return data;
}

int get_index(void)
{
	int				index = 0;
	std::wstring	input;

	while (true)
	{
		std::wcout << "Enter the index of the contact you want to see: ";
		std::getline(std::wcin, input);

		if (std::wcin.eof() || input.empty())
		{
			reopen_stdin();
			std::cerr << "Index cannot be empty!\n";
			continue;
		}
		index = ft_atoi(input);
		if (input != ft_itoa(index))
		{
			std::cerr << "Index must be a number between 0-7!\n";
			continue;
		}
		break;
	}
	return index;
}

std::wstring	trim(const std::wstring& str)
{
	std::wstring trimmed;

	if (!str.empty())
	{
		std::wstring::const_iterator it = str.begin();

		while (it != str.end())
		{
			while (it != str.end() && std::isspace(*it) != 0)
				it++;
			while (it != str.end() && std::isspace(*it) == 0)
				trimmed += *it++;
			trimmed += ' ';
		}
		
		while (!trimmed.empty() && std::isspace(*(trimmed.end() - 1)) != 0)
			trimmed.erase(trimmed.length() - 1);
	}
	return trimmed;
}

bool	valid_phone_number(const std::wstring& phoneNumber)
{
	std::wstring::const_iterator it = phoneNumber.begin();
	
	if (*it == '+')
		it++;
	while (it != phoneNumber.end())
	{
		if (std::isdigit(*it) == 0 && std::isspace(*it) == 0)
			return false;
		it++;
	}
	return (phoneNumber != L"+");
}

int	ft_atoi(const std::wstring& num)
{
	int result = 0;
	int sign = 1;
	std::wstring::const_iterator it = num.begin();

	if (*it == '-' || *it == '+')
	{
		if (*it == '-')
			sign = -1;
		it++;
	}
	while (it != num.end() && std::isdigit(*it) != 0)
	{
		result = result * 10 + *it - '0';
		it++;
	}
	return result * sign;
}

std::wstring	ft_itoa(int n)
{
	std::wstringstream ss;
	ss << n;
	return ss.str();
}

void	print_field(const std::wstring &field, int len)
{
	if (len <= 0)
		return;
	if (field.length() <= (long unsigned int)len)
		std::wcout << std::setw(len) << field;
	else
		std::wcout << field.substr(0, len - 1) << ".";
}

bool has_emoji(const std::wstring& str)
{
	std::wstring::const_iterator it;

	for (it = str.begin(); it != str.end(); it++)
	{
		if ((*it >= 0x1F600 && *it <= 0x1F64F) ||
           (*it >= 0x1F300 && *it <= 0x1F5FF) ||
           (*it >= 0x1F680 && *it <= 0x1F6FF) ||
           (*it >= 0x1F900 && *it <= 0x1F9FF) ||
           (*it >= 0x2600 && *it <= 0x26FF) ||  
           (*it >= 0x2700 && *it <= 0x27BF))
			return true;
	}
	return false;
}
//NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
