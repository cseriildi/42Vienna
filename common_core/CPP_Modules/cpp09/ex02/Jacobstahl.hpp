#pragma once
#include <vector>

class  Jacobstahl
{
	public:

		Jacobstahl();
		~Jacobstahl();
		Jacobstahl(const Jacobstahl& other);
		Jacobstahl &operator=(const Jacobstahl& other);
		unsigned int &operator[](unsigned int index);

		void reset(void);

	private:

		std::vector<unsigned int> _sequence;
		std::vector<unsigned int> _numbers;

		void generate_next(void);
};

