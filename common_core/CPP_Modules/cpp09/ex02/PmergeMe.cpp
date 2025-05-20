//NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic)

#include "Jacobstahl.hpp"
#include "PmergeMe.hpp"
#include "utils.hpp"
#include <cstddef>
#include <deque>
#include <ostream>
#include <vector>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe( char *nums[])
{
	for (int i = 1; nums[i] != NULL; i++)
	{
		unsigned int num = sto<unsigned int>(nums[i]);

		std::vector<unsigned> tmp_vec;
		tmp_vec.push_back(num);
		_vec.push_back(tmp_vec);

		std::deque<unsigned int> tmp_deq;
		tmp_deq.push_back(num);
		_deq.push_back(tmp_deq);
	}
}

PmergeMe::PmergeMe(const PmergeMe &other): _jacobstahl(other._jacobstahl), _vec(other._vec), _deq(other._deq) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (&other != this)
	{
		_jacobstahl = other._jacobstahl;
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

void PmergeMe::sortVec(void)
{

}

void PmergeMe::sortDeq(void)
{

}

const Deq2D& PmergeMe::deq(void) const {return _deq;} //NOLINT
const Vec2D& PmergeMe::vec(void) const {return _vec;} //NOLINT
void PmergeMe::empty_cache(void) {_jacobstahl.reset();}

std::ostream& operator<<(std::ostream& os, const PmergeMe& other)
{
	const Vec2D& vec = other.vec();
	for (Vec2D::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it != vec.begin())
			os << ", ";
		os << it->back();
	}
	return os << "\n";
}

//NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic)
