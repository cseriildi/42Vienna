//NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic)

#include "Jacobstahl.hpp"
#include "PmergeMe.hpp"
#include "utils.hpp"
#include <cstddef>
#include <deque>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <typeinfo>
#include <vector>

PmergeMe::PmergeMe() : _comparisons(0) {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe( char *nums[])  : _comparisons(0) 
{
	try {
		for (int i = 1; nums[i] != NULL; i++)
		{
			int num = sto<int>(nums[i]);

			if (num < 0)
				throw std::invalid_argument("Usage: ./PmergeMe <positive integers>");
			
			std::vector<unsigned> tmp_vec;
			tmp_vec.push_back(num);
			_vec.push_back(tmp_vec);

			std::deque<unsigned int> tmp_deq;
			tmp_deq.push_back(num);
			_deq.push_back(tmp_deq);
		}
	} catch (const std::bad_cast &) {
		throw std::invalid_argument("Usage: ./PmergeMe <positive integers>");
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
			indexes.push_back(indexes.back() + 1);
		}
		//debug(a, b, unmatched
		size_t skip = 0;
		for (size_t i = 0; i < b.size(); i++)
		{
			size_t j = _jacobstahl[i + skip] - 1;
			while (j >= b.size())
			{
				skip++;
				j = _jacobstahl[i + skip] - 1;
			}	
			std::vector<unsigned int> curr = b[j];
			size_t where_to = binary_search(a, curr.back(), indexes[j]);
			for (size_t k = 0; k < indexes.size(); k++)
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
	Vec2D vec = other.vec();
	typedef Vec2D::const_iterator OuterIt;
	typedef Vec2D::value_type InnerContainer;
	typedef InnerContainer::const_iterator InnerIt;

	for (OuterIt it = vec.begin(); it != vec.end(); it++)
	{
		for (InnerIt itt = (*it).begin(); itt != (*it).end(); itt++)
			os << " " << *itt;
	}
	os << "\n";
	return os;
}

//NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic)
