#include "Jacobstahl.hpp"

Jacobstahl::Jacobstahl()
{
	_numbers.push_back(0);
	_numbers.push_back(1);
	_sequence.push_back(1);
}

Jacobstahl::~Jacobstahl() {}
Jacobstahl::Jacobstahl(const Jacobstahl& other): _sequence(other._sequence), _numbers(other._numbers) {}

Jacobstahl &Jacobstahl::operator=(const Jacobstahl& other)
{
	if (&other != this)
	{
		_sequence = other._sequence;
		_numbers = other._numbers;
	}

	return *this;
}

void Jacobstahl::generate_next(void)
{
	unsigned int n = _numbers.size();

	_numbers.push_back(_numbers[n - 1] + 2 * _numbers[n - 2]);
}

unsigned int &Jacobstahl::operator[](unsigned int index)
{
	while (index >= _sequence.size())
	{
		unsigned int prev = _numbers.back();

		generate_next();
		
		for (unsigned int num = _numbers.back(); num > prev; num--)
			_sequence.push_back(num);
	}

	return _sequence[index];
}
