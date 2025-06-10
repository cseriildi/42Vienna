#pragma once

#include "Jacobsthal.hpp"

#include <cstddef>
#include <deque>
#include <vector>

#define USAGE "Usage: ./PmergeMe <positive integers>"

typedef std::vector<unsigned int> Vec;
typedef std::deque<unsigned int> Deq;
typedef std::vector<Vec> Vec2D;
typedef std::deque<Deq> Deq2D;
typedef std::vector<std::size_t> VecIndexes;
typedef std::deque<std::size_t> DeqIndexes;

template <typename Container, typename Indexes> struct Data {
  Container container;
  Container unmatched;
  Jacobsthal<Indexes> jacobsthal;
  Indexes indexes;
  std::size_t comparisons;
};

class PmergeMe {
public:
  static Vec mergeInsertionSort(const Vec &numbers);
  static Deq mergeInsertionSort(const Deq &numbers);

private:
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);

  static void merge(Data<Vec2D, VecIndexes> &data);
  static void merge(Data<Deq2D, DeqIndexes> &data);

  static Vec2D split(Data<Vec2D, VecIndexes> &data);
  static Deq2D split(Data<Deq2D, DeqIndexes> &data);

  static void insert(Data<Vec2D, VecIndexes> &data);
  static void insert(Data<Deq2D, DeqIndexes> &data);

  template <typename Container, typename Indexes>
  static std::size_t binary_search(Data<Container, Indexes> &data,
                                   unsigned int value, std::size_t end);

  template <typename Container, typename Indexes>
  static void debug(const Data<Container, Indexes> &data,
                    const Container *small = NULL);

  template <typename Container>
  static void debug(const Container &container,
                    typename Container::value_type value);
};
