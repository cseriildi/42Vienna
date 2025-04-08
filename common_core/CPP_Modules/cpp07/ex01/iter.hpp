#pragma once

#include <cstddef>

template <typename T, size_t N, typename F>
void iter(T (&array)[N], size_t length, F func)
{
	for (size_t i = 0; i < (N < length ? N : length); ++i) {
		func(*(array + i));
	}
}
