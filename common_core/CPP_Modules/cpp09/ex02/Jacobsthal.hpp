#pragma once
#include <cstddef>
#include <vector>

class  Jacobsthal
{
	public:

		Jacobsthal();
		~Jacobsthal();
		Jacobsthal(const Jacobsthal& other);
		Jacobsthal &operator=(const Jacobsthal& other);
		size_t &operator[](size_t index);

		void reset(void);

	private:

		std::vector<size_t> _sequence;
		std::vector<size_t> _numbers;

		void generate_next(void);
};

