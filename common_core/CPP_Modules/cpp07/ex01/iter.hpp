#pragma once

#include <iostream>

/* template <typename T, typename F>
void iter(T *arr, size_t length, F func)
{
	for (size_t i = 0; i < length; i++)
	{
		func(arr[i]);
	}
} */

template <typename T>
void iter(T *arr, size_t length, void (*func)(const T&))
{
	for (size_t i = 0; i < length; i++)
	{
		func(arr[i]);
	}
}

template <typename T>
void iter(T *arr, size_t length, void (*func)(T*))
{
	for (size_t i = 0; i < length; i++)
	{
		func(&arr[i]);
	}
}

template <typename T>
void display(const T& t)
{
	std::cout << t << "\n";
}

