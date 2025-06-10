#pragma once
#include <cstddef>

template <typename Container> class Jacobsthal {
public:
  Jacobsthal() {
    _numbers.push_back(0);
    _numbers.push_back(1);
    _sequence.push_back(1);
  }

  ~Jacobsthal() {}

  Jacobsthal(const Jacobsthal &other)
      : _sequence(other._sequence), _numbers(other._numbers) {}

  Jacobsthal &operator=(const Jacobsthal &other) {
    if (&other != this) {
      _sequence = other._sequence;
      _numbers = other._numbers;
    }
    return *this;
  }

  std::size_t operator[](std::size_t index) {
    while (index >= _sequence.size()) {
      const std::size_t prev = _numbers.back();

      generate_next();

      for (std::size_t num = _numbers.back(); num > prev; num--)
        _sequence.push_back(num);
    }

    return _sequence[index] - 1;
  }

  // iterators
  class Iterator {
  public:
    Iterator(Jacobsthal &parent, std::size_t index)
        : _parent(&parent), _index(index) {}

    std::size_t operator*() { return (*_parent)[_index]; }

    Iterator &operator++() {
      _index++;
      return *this;
    }

    bool operator!=(const Iterator &other) const {
      return _index != other._index;
    }

  private:
    Jacobsthal *_parent;
    std::size_t _index;
  };

  Iterator begin(void) { return Iterator(*this, 0); }
  Iterator end(void) { return Iterator(*this, _sequence.size()); }

private:
  Container _sequence;
  Container _numbers;

  void generate_next(void) {
    const std::size_t n = _numbers.size();
    _numbers.push_back(_numbers[n - 1] + (2 * _numbers[n - 2]));
  }
};
