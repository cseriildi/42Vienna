#pragma once

#include "Jacobsthal.hpp"
#include <cstddef>
#include <deque>
#include <ostream>
#include <vector>

typedef std::vector<unsigned int> Vec;
typedef std::deque<unsigned int> Deq;
typedef std::vector<Vec> Vec2D;
typedef std::deque<Deq> Deq2D;

class PmergeMe {
public:
  PmergeMe();
  PmergeMe(int argc, char *nums[]);
  ~PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);

  void sortVec();
  void sortDeq();

  const Deq2D &deq(void) const;
  const Vec2D &vec(void) const;

  void empty_cache(void);

private:
  Jacobsthal _jacobsthal;
  Vec2D _vec;
  Deq2D _deq;
  size_t _comparisons;

  template <typename Container>
  void debug(const Container &cont, const Container &unmatched);

  template <typename Container>
  void debug(const Container &cont, const Container &cont2,
             const Container &unmatched);

  template <typename Container, typename Indexes>
  void debug(const Container &curr, size_t j, const Indexes &indexes);

  template <typename Container>
  size_t binary_search(Container &container, unsigned int value, size_t end);

  void merge(Vec2D &unmatched);
  void merge(Deq2D &unmatched);

  Vec2D split(Vec2D &unmatched);
  Deq2D split(Deq2D &unmatched);

  void insert(Vec2D &unmatched);
  void insert(Deq2D &unmatched);
};

std::ostream &operator<<(std::ostream &os, const PmergeMe &other);
