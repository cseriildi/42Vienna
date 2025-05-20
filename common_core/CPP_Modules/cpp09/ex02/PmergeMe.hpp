#pragma once

#include "Jacobstahl.hpp"
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

		const Deq2D deq(void) const;
		const Vec2D vec(void) const;

		void empty_cache(void);

	private:
	
		Jacobstahl		_jacobstahl;
		Vec2D			_vec;
		Deq2D			_deq;
};

std::ostream& operator<<(std::ostream& os, const PmergeMe& other);

