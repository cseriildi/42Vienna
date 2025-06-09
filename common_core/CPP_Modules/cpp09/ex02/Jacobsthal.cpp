#include "Jacobsthal.hpp"

#include <cstddef>

Jacobsthal::Jacobsthal() {
  _numbers.push_back(0);
  _numbers.push_back(1);
  _sequence.push_back(1);
}

Jacobsthal::~Jacobsthal() {}
Jacobsthal::Jacobsthal(const Jacobsthal &other)
    : _sequence(other._sequence), _numbers(other._numbers) {}

Jacobsthal &Jacobsthal::operator=(const Jacobsthal &other) {
  if (&other != this) {
    _sequence = other._sequence;
    _numbers = other._numbers;
  }

  return *this;
}

void Jacobsthal::generate_next(void) {
  const size_t n = _numbers.size();

  _numbers.push_back(_numbers[n - 1] + (2 * _numbers[n - 2]));
}

size_t Jacobsthal::operator[](size_t index) {
  while (index >= _sequence.size()) {
    const size_t prev = _numbers.back();

    generate_next();

    for (size_t num = _numbers.back(); num > prev; num--)
      _sequence.push_back(num);
  }

  return _sequence[index] - 1;
}

void Jacobsthal::reset(void) {
  _numbers.clear();
  _sequence.clear();
  _numbers.push_back(0);
  _numbers.push_back(1);
  _sequence.push_back(1);
}

Jacobsthal::Iterator::Iterator(Jacobsthal &parent, size_t index)
    : _parent(&parent), _index(index) {}

size_t Jacobsthal::Iterator::operator*() { return (*_parent)[_index]; }

Jacobsthal::Iterator &Jacobsthal::Iterator::operator++() {
  _index++;
  return *this;
}

bool Jacobsthal::Iterator::operator!=(const Iterator &other) const {
  return _index != other._index;
}

Jacobsthal::Iterator Jacobsthal::begin(void) { return Iterator(*this, 0); }

Jacobsthal::Iterator Jacobsthal::end(void) {
  return Iterator(*this, _sequence.size());
}
