#pragma once

#include "Jacobstahl.hpp"
#include <cstddef>
#include <deque>
#include <ostream>
#include <vector>

typedef std::vector<std::vector<unsigned int> > Vec2D;
typedef std::deque<std::deque<unsigned int> > Deq2D;

class PmergeMe
{
	public:


		PmergeMe();
		PmergeMe(char *nums[]);
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
	
		Jacobstahl		_jacobstahl;
		Vec2D			_vec;
		Deq2D			_deq;
		size_t			_comparisons;
};

std::ostream& operator<<(std::ostream& os, const PmergeMe& other);

