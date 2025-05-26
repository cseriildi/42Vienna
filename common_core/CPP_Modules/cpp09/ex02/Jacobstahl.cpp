#include "Jacobstahl.hpp"
#include <cstddef>

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
	size_t n = _numbers.size();

	_numbers.push_back(_numbers[n - 1] + 2 * _numbers[n - 2]);
}

size_t &Jacobstahl::operator[](size_t index)
{
	while (index >= _sequence.size())
	{
		size_t prev = _numbers.back();

		generate_next();
		
		for (size_t num = _numbers.back(); num > prev; num--)
			_sequence.push_back(num);
	}

	return _sequence[index];
}

void Jacobstahl::reset(void)
{
	_numbers.clear();
	_sequence.clear();
	_numbers.push_back(0);
	_numbers.push_back(1);
	_sequence.push_back(1);
}
