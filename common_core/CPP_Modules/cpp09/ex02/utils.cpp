#include "utils.hpp"
#include "PmergeMe.hpp"

#include <cstddef>
#include <ostream>
#include <stdexcept>
#include <sys/_types/_timeval.h>
#include <sys/select.h>
#include <sys/time.h>
#include <typeinfo>

long now_in_microseconds() {
  timeval tv; // NOLINT
  gettimeofday(&tv, 0);
  return tv.tv_sec * 1000000L + tv.tv_usec; // NOLINT
}

Vec parse_input(int argc, char **argv) {
  Vec numbers;
  numbers.reserve(argc - 1);
  try {
    for (int i = 1; i < argc; i++) {
      const int num = sto<int>(argv[i]);

      if (num < 0)
        throw std::invalid_argument(USAGE);

      numbers.push_back(num);
    }
  } catch (const std::bad_cast &) {
    throw std::invalid_argument(USAGE);
  }
  return numbers;
}

std::size_t count_unmatched(std::size_t size) {
  std::size_t bits = 0;
  while (size > 0) {
    bits += size & 1;
    size >>= 1;
  }
  return bits - 1;
}

std::ostream &operator<<(std::ostream &os, const Vec &other) {
  for (Vec::const_iterator it = other.begin(); it != other.end(); ++it) {
    if (it != other.begin())
      os << " ";
    os << *it;
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, const Deq &other) {
  for (Deq::const_iterator it = other.begin(); it != other.end(); ++it) {
    if (it != other.begin())
      os << " ";
    os << *it;
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, const Vec2D &other) {
  os << "{";
  for (Vec2D::const_iterator it = other.begin(); it != other.end(); ++it) {
    os << "[" << *it << "]";
  }
  os << "}";
  return os;
}

std::ostream &operator<<(std::ostream &os, const Deq2D &other) {
  os << "{";
  for (Deq2D::const_iterator it = other.begin(); it != other.end(); ++it) {
    os << "[" << *it << "]";
  }
  os << "}";
  return os;
}
