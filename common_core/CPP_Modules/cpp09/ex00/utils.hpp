#pragma once

#include <cctype>
#include <limits>
#include <sstream>
#include <string>
#include <typeinfo>

bool is_valid_date(const std::string &date);
bool is_valid_value(const std::string &value);
void trim_values(std::string &date, std::string &value);
bool is_less_than_1000(const std::string &value);

template <typename T> T sto(const std::string &str) {
  if (str == "nan" || str == "nanf") {
    if (!std::numeric_limits<T>::has_quiet_NaN)
      throw std::bad_cast();
    return std::numeric_limits<T>::quiet_NaN();
  }
  if (str == "+inf" || str == "inf" || str == "+inff" || str == "inff") {
    if (!std::numeric_limits<T>::has_infinity)
      throw std::bad_cast();
    return std::numeric_limits<T>::infinity();
  }
  if (str == "-inf" || str == "-inff") {
    if (!std::numeric_limits<T>::has_infinity)
      throw std::bad_cast();
    return -std::numeric_limits<T>::infinity();
  }
  std::stringstream ss(str);
  T result;
  ss >> result;
  if (ss.fail()) {
    throw std::bad_cast();
  }
  return result;
}
