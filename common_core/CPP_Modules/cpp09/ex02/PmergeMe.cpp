// NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic)
#include "PmergeMe.hpp"
#include "../colors.hpp"
#include "Jacobsthal.hpp"
#include "utils.hpp"
#include <cstddef>
#include <deque>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <typeinfo>
#include <utility>
#include <vector>

PmergeMe::PmergeMe() : _comparisons(0) {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(int argc, char *nums[]) : _comparisons(0) {
  try {
    _vec.reserve(argc - 1);
    for (int i = 1; i < argc; i++) {
      int num = sto<int>(nums[i]);

      if (num < 0)
        throw std::invalid_argument("Usage: ./PmergeMe <positive integers>");

      _vec.push_back(Vec(1, num));
      _deq.push_back(Deq(1, num));
    }
  } catch (const std::bad_cast &) {
    throw std::invalid_argument("Usage: ./PmergeMe <positive integers>");
  }
}

PmergeMe::PmergeMe(const PmergeMe &other)
    : _jacobsthal(other._jacobsthal), _vec(other._vec), _deq(other._deq),
      _comparisons(other._comparisons) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (&other != this) {
    _jacobsthal = other._jacobsthal;
    _vec = other._vec;
    _deq = other._deq;
    _comparisons = other._comparisons;
  }
  return *this;
}

template <typename Container>
size_t PmergeMe::binary_search(Container &container, unsigned int value,
                               size_t end) // NOLINT
{
  size_t start = 0;
  while (start < end) {
    size_t mid = start + (end - start) / 2;
    _comparisons++;
    if (DEBUG)
      std::cout << PURPLE "Comparing " << value << " with "
                << container[mid].back() << RESET "\n";
    if (container[mid].back() == value)
      return mid;
    if (container[mid].back() < value)
      start = mid + 1;
    else
      end = mid;
  }
  return start;
}

void PmergeMe::merge(Vec2D &unmatched) {
  Vec2D tmp;
  tmp.reserve(_vec.size() / 2);
  Vec2D::iterator it = _vec.begin();
  while (it < _vec.end()) {
    Vec &curr_vec = *it;
    // IF IT HAS NO PAIR, MOVE IT TO UNMATCHED
    if (it + 1 == _vec.end()) {
      // this is better than: unmatched.push_back(curr_vec); because it avoids
      // copying
      unmatched.push_back(Vec());
      unmatched.back().swap(curr_vec);
    } else {
      Vec &next_vec = *(it + 1);

      // MERGE ITS PAIR TO THE BEGINNING OR END OF THE CURRENT VECTOR BASED ON
      // THE LAST ELEMENTS
      Vec *smaller = &curr_vec;
      Vec *bigger = &next_vec;

      ++_comparisons;
      if (next_vec.back() < curr_vec.back())
        std::swap(smaller, bigger);
      // insert at end is better (O(1)) than at begin (O(n)) because it calls
      // .push_back() internally
      smaller->insert(smaller->end(), bigger->begin(), bigger->end());
      tmp.push_back(Vec());
      tmp.back().swap((*smaller));
    }
    it += 2;
  }
  _vec = tmp;
  debug(_vec, unmatched);
}

void PmergeMe::merge(Deq2D &unmatched) {
  Deq2D::iterator it = _deq.begin();

  Deq2D tmp;
  tmp.resize(_deq.size() / 2); // creates default elements (empty deques)

  for (Deq2D::iterator tmp_it = tmp.begin(); tmp_it != tmp.end();
       ++tmp_it, it += 2) {
    Deq &curr_deq = *it;
    Deq &next_deq = *(it + 1);
    Deq::iterator where_to =
        (next_deq.back() > curr_deq.back() ? curr_deq.end() : curr_deq.begin());
    ++_comparisons;
    // insert at begin or end of deque is O(1)
    curr_deq.insert(where_to, next_deq.begin(), next_deq.end());
    tmp_it->swap(curr_deq);
  }
  if (it != _deq.end()) {
    unmatched.push_back(Deq());
    unmatched.back().swap(*it);
  }
  _deq = tmp;
}

Vec2D PmergeMe::split(Vec2D &unmatched) {
  size_t size = _vec.back().size() / 2;
  bool unmatched_found =
      (!unmatched.empty() && unmatched.back().size() == size);

  Vec2D small;
  small.reserve(_vec.size() + unmatched_found); // NOLINT

  for (Vec2D::iterator current = _vec.begin(); current != _vec.end();
       current++) {
    Vec &big = *current;
    // SPLIT EACH CONTAINER IN HALF AND MOVE THE FIRST HALF TO SMALL
    small.push_back(Vec(big.begin(), big.begin() + size)); // NOLINT
    big = Vec(big.begin() + size, big.end());              // NOLINT
  }
  debug(_vec, small, unmatched);

  // PUT UNMATCHED CONTAINER WITH SAME SIZE INTO SMALL
  if (unmatched_found) {
    small.push_back(Vec());
    small.back().swap(unmatched.back());
    unmatched.pop_back();
    debug(_vec, small, unmatched);
  }
  return small;
}
Deq2D PmergeMe::split(Deq2D &unmatched) {
  size_t size = _deq.back().size() / 2;
  bool unmatched_found =
      (!unmatched.empty() && unmatched.back().size() == size);

  Deq2D small;
  small.resize(_deq.size() + unmatched_found); // NOLINT
  Deq2D::iterator small_it = small.begin();

  for (Deq2D::iterator current = _deq.begin(); current != _deq.end();
       current++, ++small_it) {
    Deq &big = *current;
    *small_it = Deq(big.begin(), big.begin() + size); // NOLINT
    // erasing in the beginning does not create shifts or copies (unlike in
    // vectors)
    big.erase(big.begin(), big.begin() + size); // NOLINT
  }
  if (unmatched_found) {
    small_it->swap(unmatched.back());
    unmatched.pop_back();
  }
  return small;
}

void PmergeMe::insert(Vec2D &unmatched) {
  Vec2D small = split(unmatched);
  Vec2D &big = _vec;

  std::vector<size_t> indexes;
  indexes.resize(small.size());
  for (size_t i = 0; i < small.size(); i++)
    indexes[i] = i;

  Jacobsthal::Iterator j_it = _jacobsthal.begin();
  for (size_t i = 0; i < small.size(); i++, ++j_it) {
    // GET JACOBSTHAL NUMBER
    while (*j_it >= small.size())
      ++j_it;
    size_t jacobsthal = *j_it;

    // THE CONTAINER TO INSERT BASED ON JACOBSTHAL NUMBER
    Vec &curr = small[jacobsthal];
    debug(curr, jacobsthal, indexes);

    // BINARY SEARCH WHERE TO INSERT
    size_t where_to = binary_search(big, curr.back(), indexes[jacobsthal]);

    // ADJUST INDEXES THAT ARE AFTER THE INSERTION POINT
    for (size_t k = where_to; k < indexes.size(); k++)
      ++indexes[k];

    // INSERT
    big.insert(big.begin() + where_to, Vec()); // NOLINT
    curr.swap(big[where_to]);
    debug(big, small, unmatched);
  }
  debug(big, unmatched);
}

void PmergeMe::insert(Deq2D &unmatched) {
  Deq2D small = split(unmatched);
  Deq2D &big = _deq;

  std::deque<size_t> indexes;
  indexes.resize(small.size());
  for (size_t i = 0; i < small.size(); i++)
    indexes[i] = i;

  Jacobsthal::Iterator j_it = _jacobsthal.begin();
  for (size_t i = 0; i < small.size(); i++, ++j_it) {
    while (*j_it >= small.size())
      ++j_it;
    size_t jacobsthal = *j_it;

    Deq &curr = small[jacobsthal];

    size_t where_to = binary_search(big, curr.back(), indexes[jacobsthal]);

    for (size_t k = where_to; k < indexes.size(); k++)
      ++indexes[k];

    big.insert(big.begin() + where_to, Deq()); // NOLINT
    curr.swap(big[where_to]);
  }
}

size_t count_unmatched(size_t size) {
  size_t bits = 0;
  while (size > 0) {
    bits += size & 1;
    size >>= 1;
  }
  return bits - 1;
}

void PmergeMe::sortVec(void) {
  Vec2D unmatched;
  unmatched.reserve(count_unmatched(_vec.size()));

  debug(_vec, unmatched);
  while (_vec.size() > 1)
    merge(unmatched);
  while (_vec.back().size() > 1)
    insert(unmatched);
}

void PmergeMe::sortDeq(void) {
  Deq2D unmatched;

  while (_deq.size() > 1)
    merge(unmatched);
  while (_deq.back().size() > 1)
    insert(unmatched);
}

const Deq2D &PmergeMe::deq(void) const { return _deq; } // NOLINT
const Vec2D &PmergeMe::vec(void) const { return _vec; } // NOLINT
void PmergeMe::empty_cache(void) {
  _jacobsthal.reset();
  _comparisons = 0;
}

std::ostream &operator<<(std::ostream &os, const PmergeMe &other) {
  const Vec2D &vec = other.vec();
  typedef Vec2D::const_iterator OuterIt;
  typedef Vec2D::value_type InnerContainer;
  typedef InnerContainer::const_iterator InnerIt;

  for (OuterIt it = vec.begin(); it != vec.end(); it++) {
    for (InnerIt itt = (*it).begin(); itt != (*it).end(); itt++)
      os << " " << *itt;
  }
  os << "\n";
  return os;
}

template <typename Container>
void PmergeMe::debug(const Container &cont,
                     const Container &unmatched) // NOLINT
{
  if (DEBUG) {
    print2D(cont, GREEN);
    print2D(unmatched, BLUE);
    std::cout << "\nNumber of comparisons: " << _comparisons << "\n";
  }
}

template <typename Container>
void PmergeMe::debug(const Container &cont, const Container &cont2,
                     const Container &unmatched) // NOLINT
{
  if (DEBUG) {
    print2D(cont, GREEN);
    print2D(cont2, YELLOW);
    print2D(unmatched, BLUE);
    std::cout << "\n";
  }
}
template <typename Container, typename Indexes>
void PmergeMe::debug(const Container &curr, size_t j, const Indexes &indexes) {
  if (DEBUG) {
    std::cout << CYAN "Jacobstahl number: " << j + 1 << ", Inserting: [ ";
    for (typename Container::const_iterator it = curr.begin(); it != curr.end();
         it++)
      std::cout << *it << " ";
    std::cout << "], Binary search before index " << indexes[j] << "\n" RESET;
  }
}
// NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic)
