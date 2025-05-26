#pragma once
#include <cstddef>
#include <vector>

class  Jacobstahl
{
	public:

		Jacobstahl();
		~Jacobstahl();
		Jacobstahl(const Jacobstahl& other);
		Jacobstahl &operator=(const Jacobstahl& other);
		size_t &operator[](size_t index);

		void reset(void);

	private:

		std::vector<size_t> _sequence;
		std::vector<size_t> _numbers;

		void generate_next(void);
};

