#include "PmergeMe.hpp"
#include "../colors.hpp"
#include "Jacobsthal.hpp"
#include "utils.hpp"

#include <cstddef>
#include <deque>
#include <iostream>
#include <ostream>
#include <utility>
#include <vector>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  (void)other;
  return *this;
}

Vec PmergeMe::mergeInsertionSort(const Vec &numbers) {
  Data<Vec2D, VecIndexes> data;
  const std::size_t count = numbers.size();
  data.container.reserve(count);
  data.unmatched.reserve(count_unmatched(count));
  data.comparisons = 0;

  for (Vec::const_iterator it = numbers.begin(); it != numbers.end(); it++)
    data.container.push_back(Vec(1, *it));

#ifdef DEBUG
  debug(data);
#endif

  while (data.container.size() > 1)
    merge(data);
  while (data.container.back().size() > 1)
    insert(data);

  Vec sorted;
  sorted.reserve(count);
  for (Vec2D::const_iterator it = data.container.begin();
       it != data.container.end(); it++)
    sorted.push_back((*it).back());

  return sorted;
}

Deq PmergeMe::mergeInsertionSort(const Deq &numbers) {
  Data<Deq2D, DeqIndexes> data;
  data.comparisons = 0;

  for (Deq::const_iterator it = numbers.begin(); it != numbers.end(); it++)
    data.container.push_back(Deq(1, *it));

  while (data.container.size() > 1)
    merge(data);
  while (data.container.back().size() > 1)
    insert(data);

  Deq sorted;
  for (Deq2D::const_iterator it = data.container.begin();
       it != data.container.end(); it++)
    sorted.push_back((*it).back());

  return sorted;
}

void PmergeMe::merge(Data<Vec2D, VecIndexes> &data) {
  Vec2D tmp;
  tmp.reserve(data.container.size() / 2);
  Vec2D::iterator it = data.container.begin();
  while (it < data.container.end()) {
    Vec &curr_vec = *it;
    // IF IT HAS NO PAIR, MOVE IT TO UNMATCHED
    if (it + 1 == data.container.end()) {
      // this is better than unmatched.push_back(curr_vec); it avoids copying
      data.unmatched.push_back(Vec());
      data.unmatched.back().swap(curr_vec);
    } else {
      Vec &next_vec = *(it + 1);

      // MERGE ITS PAIR TO BEGIN OR END BASED ON THE LAST ELEMENTS
      Vec *smaller = &curr_vec;
      Vec *bigger = &next_vec;

      ++data.comparisons;
      if (next_vec.back() < curr_vec.back())
        std::swap(smaller, bigger);
      // insert at begin is(O(n)) because it calls .push_back()
      smaller->insert(smaller->end(), bigger->begin(), bigger->end());
      tmp.push_back(Vec());
      tmp.back().swap((*smaller));
    }
    it += 2;
  }
  data.container = tmp;
#ifdef DEBUG
  debug(data);
#endif
}

void PmergeMe::merge(Data<Deq2D, DeqIndexes> &data) {
  Deq2D tmp;
  // creates default elements (empty deques)
  tmp.resize(data.container.size() / 2);

  Deq2D::iterator it = data.container.begin();

  for (Deq2D::iterator tmp_it = tmp.begin(); tmp_it != tmp.end();
       ++tmp_it, it += 2) {
    Deq &curr_deq = *it;
    Deq &next_deq = *(it + 1);
    const Deq::iterator where_to =
        (next_deq.back() > curr_deq.back() ? curr_deq.end() : curr_deq.begin());
    ++data.comparisons;
    // insert at begin or end of deque is O(1)
    curr_deq.insert(where_to, next_deq.begin(), next_deq.end());
    tmp_it->swap(curr_deq);
  }
  if (it != data.container.end()) {
    data.unmatched.push_back(Deq());
    data.unmatched.back().swap(*it);
  }
  data.container = tmp;
}

Vec2D PmergeMe::split(Data<Vec2D, VecIndexes> &data) {
  const std::size_t size = data.container.back().size() / 2;
  const bool unmatched_found =
      (!data.unmatched.empty() && data.unmatched.back().size() == size);

  Vec2D small;
  small.reserve(data.container.size() + unmatched_found); // NOLINT

  for (Vec2D::iterator current = data.container.begin();
       current != data.container.end(); current++) {
    Vec &big = *current;
    // SPLIT EACH CONTAINER IN HALF AND MOVE THE FIRST HALF TO SMALL
    small.push_back(Vec(big.begin(), big.begin() + size)); // NOLINT
    big = Vec(big.begin() + size, big.end());              // NOLINT
  }

#ifdef DEBUG
  debug(data, &small);
#endif

  // PUT UNMATCHED CONTAINER WITH SAME SIZE INTO SMALL
  if (unmatched_found) {
    small.push_back(Vec());
    small.back().swap(data.unmatched.back());
    data.unmatched.pop_back();

#ifdef DEBUG
    debug(data, &small);
#endif
  }
  return small;
}

Deq2D PmergeMe::split(Data<Deq2D, DeqIndexes> &data) {
  const std::size_t size = data.container.back().size() / 2;
  const bool unmatched_found =
      (!data.unmatched.empty() && data.unmatched.back().size() == size);

  Deq2D small;
  small.resize(data.container.size() + unmatched_found); // NOLINT
  Deq2D::iterator small_it = small.begin();

  for (Deq2D::iterator current = data.container.begin();
       current != data.container.end(); current++, ++small_it) {
    Deq &big = *current;
    *small_it = Deq(big.begin(), big.begin() + size); // NOLINT
    // erase at begin doesn't shift or copy (unlike in vectors)
    big.erase(big.begin(), big.begin() + size); // NOLINT
  }
  if (unmatched_found) {
    small_it->swap(data.unmatched.back());
    data.unmatched.pop_back();
  }
  return small;
}

void PmergeMe::insert(Data<Vec2D, VecIndexes> &data) {
  Vec2D small = split(data);
  Vec2D &big = data.container;

  data.indexes.resize(small.size());
  for (std::size_t i = 0; i < small.size(); i++)
    data.indexes[i] = i;

  Jacobsthal<VecIndexes>::Iterator j_it = data.jacobsthal.begin();
  for (std::size_t i = 0; i < small.size(); i++, ++j_it) {
    // GET JACOBSTHAL NUMBER
    while (*j_it >= small.size())
      ++j_it;
    const std::size_t jacobsthal = *j_it;

    // THE CONTAINER TO INSERT BASED ON JACOBSTHAL NUMBER
    Vec &curr = small[jacobsthal];

#ifdef DEBUG
    std::cout << CYAN "Jacobstahl number: " << jacobsthal + 1
              << ", Inserting: [" << curr << "], Binary search before index "
              << data.indexes[jacobsthal] << "\n" RESET;
#endif

    // BINARY SEARCH WHERE TO INSERT
    const std::size_t where_to =
        binary_search(data, curr.back(), data.indexes[jacobsthal]);

    // ADJUST INDEXES THAT ARE AFTER THE INSERTION POINT
    for (std::size_t k = where_to; k < data.indexes.size(); k++)
      ++data.indexes[k];

    // INSERT
    big.insert(big.begin() + where_to, Vec()); // NOLINT
    curr.swap(big[where_to]);

#ifdef DEBUG
    debug(data, &small);
#endif
  }
#ifdef DEBUG
  debug(data);
#endif
}

void PmergeMe::insert(Data<Deq2D, DeqIndexes> &data) {
  Deq2D small = split(data);
  Deq2D &big = data.container;

  data.indexes.resize(small.size());
  for (std::size_t i = 0; i < small.size(); i++)
    data.indexes[i] = i;

  Jacobsthal<DeqIndexes>::Iterator j_it = data.jacobsthal.begin();
  for (std::size_t i = 0; i < small.size(); i++, ++j_it) {
    while (*j_it >= small.size())
      ++j_it;
    const std::size_t jacobsthal = *j_it;

    Deq &curr = small[jacobsthal];

    const std::size_t where_to =
        binary_search(data, curr.back(), data.indexes[jacobsthal]);

    for (std::size_t k = where_to; k < data.indexes.size(); k++)
      ++data.indexes[k];

    big.insert(big.begin() + where_to, Deq()); // NOLINT
    curr.swap(big[where_to]);
  }
}

template <typename Container, typename Indexes>
std::size_t PmergeMe::binary_search(Data<Container, Indexes> &data,
                                    unsigned int value, std::size_t end) {
  std::size_t start = 0;
  while (start < end) {
    const std::size_t mid = start + ((end - start) / 2);
    data.comparisons++;

#ifdef DEBUG
    debug(data.container[mid], value);
#endif

    if (data.container[mid].back() == value)
      return mid;
    if (data.container[mid].back() < value)
      start = mid + 1;
    else
      end = mid;
  }
  return start;
}

template <typename Container, typename Indexes>
void PmergeMe::debug(const Data<Container, Indexes> &data,
                     const Container *small) {
  std::cout << GREEN << data.container;
  if (small != NULL)
    std::cout << YELLOW << *small;
  std::cout << BLUE << data.unmatched << RESET "\n";
  if (small == NULL)
    std::cout << "Number of comparisons: " << data.comparisons << "\n";
}

template <typename Container>
void PmergeMe::debug(const Container &container,
                     typename Container::value_type value) {
  (void)container;
  (void)value;
}

template <> void PmergeMe::debug(const Vec &container, unsigned int value) {
  std::cout << PURPLE "Comparing " << value << " with " << container.back()
            << RESET "\n";
}
