#pragma once

#include "PmergeMe.hpp"

#include <cstddef>
#include <limits>
#include <ostream>
#include <sstream>
#include <string>
#include <typeinfo>

long now_in_microseconds();
Vec parse_input(int argc, char **argv);
std::size_t count_unmatched(std::size_t size);
std::ostream &operator<<(std::ostream &os, const Vec &other);
std::ostream &operator<<(std::ostream &os, const Deq &other);
std::ostream &operator<<(std::ostream &os, const Vec2D &other);
std::ostream &operator<<(std::ostream &os, const Deq2D &other);

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
  if (ss.fail() || !ss.eof()) {
    throw std::bad_cast();
  }
  return result;
}
