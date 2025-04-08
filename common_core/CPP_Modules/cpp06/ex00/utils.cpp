#include "utils.hpp"

#include <cctype>
#include <string>

NumberType detect_type(const std::string& str)
{
	if (str == "nan" || str == "+inf" || str == "inf" || str == "-inf") {
		return DOUBLE;
	}
	if (str == "nanf" || str == "+inff" || str == "inff" || str == "-inff") {
		return FLOAT;
	}
	if (str.empty()) {
		return NaN;
	}
	if (str.length() == 1 && isdigit(str[0]) == 0) {
		return CHAR;
	}
	int dot_count = 0;
	int sign = static_cast<int>(*str.begin() == '+' || *str.begin() == '-');

	for (std::string::const_iterator it = str.begin() + sign; it != str.end(); it++)
	{
		if (isdigit(*it) == 0)
		{
			if (*it == '.')
			{
				if (++dot_count > 1)
					return NaN;
				continue;
			}
			if (*it == 'f' && it + 1 == str.end()
				&& dot_count == 1
				&& str.length() - sign - dot_count > 1)
				return FLOAT;
			return NaN;
		}
	}
	return dot_count == 0 ? INTEGER : DOUBLE;
}
