#pragma once

#include "Jacobsthal.hpp"
#include <cstddef>
#include <deque>
#include <ostream>
#include <vector>

typedef std::vector<unsigned int> Vec;
typedef std::deque<unsigned int>  Deq;
typedef std::vector<Vec> Vec2D;
typedef std::deque<Deq> Deq2D;

class PmergeMe
{
	public:


		PmergeMe();
		PmergeMe(int argc, char *nums[]);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void sortVec();
		void sortDeq();

		const Deq2D& deq(void) const;
		const Vec2D& vec(void) const;

		void empty_cache(void);

		template <typename T>
		size_t binary_search(T &container, unsigned int value, size_t end);

	private:
	
		Jacobsthal		_jacobsthal;
		Vec2D			_vec;
		Deq2D			_deq;
		size_t			_comparisons;
};

std::ostream& operator<<(std::ostream& os, const PmergeMe& other);

