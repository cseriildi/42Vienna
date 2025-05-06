# About the CPP Module 08 project

## Summary
The goal of the CPP Module projects is to get familiar with C++ programming language quickly.
This project specifically focuses on `templated containers`, `iterators` and `algorithms`.

>**Allowed:** Any function from the standard library. If there is a C++ version of a function, use that. The code must compile with C++98.
>
>**Forbidden:** Any function from external libraries, as well as `*printf()`, `*alloc()` and `free()`.

## Useful Stuff
- [Introduction to containers and arrays](https://www.learncpp.com/cpp-tutorial/introduction-to-containers-and-arrays/)
- [Introduction to iterators](https://www.learncpp.com/cpp-tutorial/introduction-to-iterators/)
- [Introduction to standard library algorithms](https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/)

## Exercise 00
- Implement a templated function `easyfind` that takes a container and a value, and returns an iterator to the first occurrence of the value in the container.
- If the value is not found, throw an exception.

## Exercise 01
- Create a class `Span` that can store integers.
- Implement the following member functions:
  - `addNumber(int n)`: Adds a number to the container.
  - Implement a funcitonto add a range of numbers in one call.
  - `shortestSpan()`: Returns the shortest span (distance) between any two numbers.
  - `longestSpan()`: Returns the longest span (distance) between any two numbers.

## Exercise 02
- Create a class `MutantStack` that inherits from `std::stack`.
- Make the class iterable.
