# About the CPP Module 07 project

## Summary
The goal of the CPP Module projects is to get familiar with C++ programming language quickly.
This project specifically focuses on `templates`.

>**Allowed:** Any function from the standard library. If there is a C++ version of a function, use that. The code must compile with C++98.
>
>**Forbidden:** Any function from external libraries, as well as `*printf()`, `*alloc()` and `free()`. Containers (`vector`, `list`, `map`, ...) and algorithms (functions from the `algorithm` header).

## Useful Stuff
- [Function template specialization](https://www.learncpp.com/cpp-tutorial/function-template-specialization/)
- [Template classes](https://www.learncpp.com/cpp-tutorial/template-classes/)

## Exercise 00
- Implement a template function `swap(T &a, T &b)` that swaps two values.
- Implement template functions `min(T const &a, T const &b)` and `max(T const &a, T const &b)`

## Exercise 01
- Create a template function `iter` that takes these parameters:
  - the address of an array
  - the length of the array
  - a function that will be called on each element of the array

## Exercise 02
- Create a class template `Array<T>` that:
  - Overloads `[]` operator, when indexing out of bound throw exception
- Add `size()` member function
