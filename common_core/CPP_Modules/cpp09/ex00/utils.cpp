//NOLINTBEGIN(readability-magic-numbers)

#include "utils.hpp"

#include <cctype>
#include <cstddef>
#include <string>
#include <typeinfo>

bool is_only_digit(const std::string& num)
{
	for (std::string::const_iterator it = num.begin(); it != num.end(); it++)
	{
		if (std::isdigit(*it) == 0)
			return false;
	}
	return true;
}

bool is_valid_date(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr( 5, 2);
	std::string dayStr = date.substr( 8, 2);

	if (!is_only_digit(yearStr) || !is_only_digit(monthStr) || !is_only_digit(dayStr))
		return  false;

	try {
		int year = sto<int>(yearStr);
		int month = sto<int>(monthStr);
		int day = sto<int>(dayStr);

		if (month < 1 || month > 12 || day < 1 || day > 31)
			return false;
		if (month == 2 && day > 28)
			return (day == 29 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
			return false;

	} catch (const std::bad_cast&) {
		return false;
	}

	return true;
}

bool is_valid_value(const std::string& value)
{
	int is_negative =  (int)(*value.begin() == '-');
	std::string::const_iterator it = value.begin() + is_negative;
	int dot_count = 0;


	for (; it != value.end(); it++)
	{
		if (*it == '.')
		{
			if (++dot_count != 1)
				return false;
		}
		else if (std::isdigit(*it) == 0)
			return false;
	}
	return it != (value.begin() + is_negative + dot_count);
}

void trim_values(std::string &date, std::string &value)
{
	date.erase(date.size() - 1); //trim space at the end
	value.erase(0, 1); //trim space in the beginning
	int is_negative = (int)(*value.begin() == '-');

	while (value != "0" && *(value.begin() + is_negative) == '0')
		value.erase(is_negative, 1);

	if (value.find('.') != std::string::npos)
	{
		while (*(value.end() - 1) == '0')
			value.erase(value.size() - 1);
	
		if (*(value.end() - 1) == '.')
			value.erase(value.size() - 1);
	}
}

bool is_less_than_1000(const std::string &value)
{
	size_t dot_pos = value.find('.');

	return  (dot_pos == std::string::npos && (value.length() <= 3 || value == "1000")) || dot_pos <= 3;
}

//NOLINTEND(readability-magic-numbers)
