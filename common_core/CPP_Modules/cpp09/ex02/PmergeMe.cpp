//NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic)

#include "Jacobstahl.hpp"
#include "PmergeMe.hpp"
#include "utils.hpp"
#include <cstddef>
#include <deque>
#include <iostream>
#include <ostream>
#include <vector>

PmergeMe::PmergeMe() : _comparisons(0) {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe( char *nums[])  : _comparisons(0) 
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

PmergeMe::PmergeMe(const PmergeMe &other): _jacobstahl(other._jacobstahl),
											_vec(other._vec),
											_deq(other._deq),
											_comparisons(other._comparisons) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (&other != this)
	{
		_jacobstahl = other._jacobstahl;
		_vec = other._vec;
		_deq = other._deq;
		_comparisons = other._comparisons;
	}
	return *this;
}

template <typename T>
size_t PmergeMe::binary_search(T &container, unsigned int value, size_t end) //NOLINT
{
	size_t start = 0;
	while (start < end)
	{
		size_t mid = start + (end - start) / 2;
		_comparisons++;
		if (container[mid].back() == value)
			return mid;
		if (container[mid].back() < value)
			start = mid + 1;
		else
			end = mid;
	}
	return start;
}

void PmergeMe::sortVec(void)
{
	Vec2D unmatched;
	//TODO: conditional compilation to print the number of comparisons

	while (_vec.size() > 1)
	{
		for (Vec2D::iterator current = _vec.begin(); current != _vec.end(); current++)
		{
			Vec2D::iterator next = current + 1;
			std::vector<unsigned int> &curr_vec = *current;

			if (next == _vec.end())
			{
				unmatched.push_back(curr_vec);
				_vec.erase(current);
				break;
			}
			std::vector<unsigned int> &next_vec = *next;


			std::vector<unsigned int>::iterator where_to = (next_vec.back() > curr_vec.back() ? curr_vec.end() : curr_vec.begin());
			_comparisons++;
			curr_vec.insert(where_to, next_vec.begin(), next_vec.end());
			_vec.erase(next);
		}
	}
	size_t size = _vec.back().size();
	while (size > 1)
	{
		size /= 2;
		Vec2D &a = _vec;
		Vec2D b;
		std::vector<size_t> indexes;

		for (Vec2D::iterator current = _vec.begin(); current != _vec.end(); current++)
		{
			std::vector<unsigned int> tmp;
			
			tmp.insert(tmp.begin(), (*current).begin(), (*current).begin() + size); //NOLINT
			b.push_back(tmp);
			(*current).erase((*current).begin(), (*current).begin() + size); //NOLINT

			if (indexes.empty())
				indexes.push_back(0);
			else
			 	indexes.push_back(indexes.back() + 1);
		}
		if (!unmatched.empty() && unmatched.back().size() == size)
		{
			b.push_back(unmatched.back());
			unmatched.pop_back();
			//TODO: think about unmatched
		}

		for (size_t i = 0; i < size; i++)
		{
			size_t j = _jacobstahl[i] - 1;
			if (j >= size)
				continue;
			std::vector<unsigned int> curr = b[j];
			size_t where_to = binary_search(a, curr.back(), indexes[j]);
			for (size_t k = 0; k < size; k++)
			{
				if (where_to <= indexes[k])
					indexes[k]++;
			}
			a.insert(a.begin() + where_to, curr); //NOLINT
		}
	}
	std::cout << "Number of comparisons: " << _comparisons << "\n";
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
		for (std::vector<unsigned int>::const_iterator itt = (*it).begin(); itt != (*it).end(); itt++)
		{
			if (it != vec.begin() || itt != (*it).begin())
				os << ", ";
			os << *itt;
		}
	}
	return os << "\n";
}

//NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic)
