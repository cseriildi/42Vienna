//NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic)

#include "Jacobsthal.hpp"
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

PmergeMe::PmergeMe(int argc, char *nums[])  : _comparisons(0) 
{
	try {
		_vec.reserve(argc - 1);
		for (int i = 1; i < argc; i++)
		{
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

PmergeMe::PmergeMe(const PmergeMe &other): _jacobsthal(other._jacobsthal),
											_vec(other._vec),
											_deq(other._deq),
											_comparisons(other._comparisons) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (&other != this)
	{
		_jacobsthal = other._jacobsthal;
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
		//std::cout << PURPLE << "Comparing " << value << " with " << container[mid].back() << RESET << "\n";
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
	//debug(_vec, unmatched);
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
		/* debug(_vec, unmatched);
		std::cout << "Number of comparisons: " << _comparisons << "\n"; */
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
		//debug(a, b, unmatched);
		size_t skip = 0;
		for (size_t i = 0; i < b.size(); i++)
		{
			size_t j = _jacobsthal[i + skip] - 1;
			while (j >= b.size())
			{
				skip++;
				j = _jacobsthal[i + skip] - 1;
			}	
			std::vector<unsigned int> &curr = b[j];
	/* 		std::cout << CYAN "Jacobstahl number: " << j + 1 << ", Inserting: [ ";
			for (size_t k = 0; k < curr.size(); k++)
				std::cout << curr[k] << " ";
			std::cout << "], Binary search before index " << indexes[j] << "\n" RESET; */
			size_t where_to = binary_search(a, curr.back(), indexes[j]);
			for (size_t k = 0; k < indexes.size(); k++)
			{
				if (where_to <= indexes[k])
					indexes[k]++;
			}
			a.insert(a.begin() + where_to, curr); //NOLINT
			curr.clear();
			//debug(a, b, unmatched);
		}
		//debug(_vec, unmatched);
		//std::cout << "Number of comparisons: " << _comparisons << "\n";
	}
}

void PmergeMe::sortDeq(void)
{
	Deq2D unmatched;
	//TODO: conditional compilation to print the number of comparisons
	//debug(_vec, unmatched);
	while (_deq.size() > 1)
	{
		for (Deq2D::iterator current = _deq.begin(); current != _deq.end(); current++)
		{
			Deq2D::iterator next = current + 1;
			std::deque<unsigned int> &curr_deq = *current;

			if (next == _deq.end())
			{
				unmatched.push_back(*current);
				_deq.erase(current);
				break;
			}
			std::deque<unsigned int> &next_deq = *next;


			std::deque<unsigned int>::iterator where_to = (next_deq.back() > curr_deq.back() ? curr_deq.end() : curr_deq.begin());
			_comparisons++;
			curr_deq.insert(where_to, next_deq.begin(), next_deq.end());
			_deq.erase(next);
		}
		/* debug(_deq, unmatched);
		std::cout << "Number of comparisons: " << _comparisons << "\n"; */
	}
	size_t size = _deq.back().size();
	while (size > 1)
	{
		size /= 2;
		Deq2D &a = _deq;
		Deq2D b;
		std::deque<size_t> indexes;

		for (Deq2D::iterator current = _deq.begin(); current != _deq.end(); current++)
		{
			std::deque<unsigned int> tmp;
			
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
		//debug(a, b, unmatched);
		size_t skip = 0;
		for (size_t i = 0; i < b.size(); i++)
		{
			size_t j = _jacobsthal[i + skip] - 1;
			while (j >= b.size())
			{
				skip++;
				j = _jacobsthal[i + skip] - 1;
			}	
			std::deque<unsigned int> &curr = b[j];
	/* 		std::cout << CYAN "Jacobstahl number: " << j + 1 << ", Inserting: [ ";
			for (size_t k = 0; k < curr.size(); k++)
				std::cout << curr[k] << " ";
			std::cout << "], Binary search before index " << indexes[j] << "\n" RESET; */
			size_t where_to = binary_search(a, curr.back(), indexes[j]);
			for (size_t k = 0; k < indexes.size(); k++)
			{
				if (where_to <= indexes[k])
					indexes[k]++;
			}
			a.insert(a.begin() + where_to, curr); //NOLINT
			curr.clear();
			//debug(a, b, unmatched);
		}
		//debug(_deq, unmatched);
		//std::cout << "Number of comparisons: " << _comparisons << "\n";
	}
}

const Deq2D& PmergeMe::deq(void) const {return _deq;} //NOLINT
const Vec2D& PmergeMe::vec(void) const {return _vec;} //NOLINT
void PmergeMe::empty_cache(void) {_jacobsthal.reset();}

std::ostream& operator<<(std::ostream& os, const PmergeMe& other)
{
	const Vec2D &vec = other.vec();
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
