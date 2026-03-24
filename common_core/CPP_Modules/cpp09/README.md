# About the CPP Module 09 project

## Summary
The goal of the CPP Module projects is to get familiar with C++ programming language quickly.
This project specifically focuses on `containers`.

>**Allowed:** Any function from the standard library. If there is a C++ version of a function, use that. The code must compile with C++98.
>
>**Forbidden:** Any function from external libraries, as well as `*printf()`, `*alloc()` and `free()`.

## Useful Stuff
- [Kamilla's very detailed description of the Ford-Johnson algorithm](https://github.com/leske42/CPP09/blob/main/README.md)
- [Art Of Computer Programming, Vol.3.](https://seriouscomputerist.atariverse.com/media/pdf/book/Art%20of%20Computer%20Programming%20-%20Volume%203%20(Sorting%20&%20Searching).pdf)

## Exercise 00

Create a program that outputs the value of a certain amount of bitcoin on a certain date.
  - The program `btc` takes a file as an argument, which contains lines in the format `"date | value"`.
  - It uses a provided `data.csv` file as a database for Bitcoin prices.
  - It must calculate and display the value of the Bitcoin amount for the given date.
  - If a date from the input is not found in the database, the closest date before it must be used.
  - Must handle errors such as invalid dates, non-positive numbers, or numbers larger than 1000.
  - Requires the use of at least one STL container.

## Exercise 01

Write a program to evaluate a mathematical expression written in Reverse Polish Notation (RPN).
  - The program `RPN` takes the expression as a single string argument (e.g., `"8 9 * 9 -"`).
  - It must support the operators: `+`, `-`, `*`, `/`.
  - The numbers in the input expression will be single digits (0-9).
  - It must print the correct result or an error message if the expression is invalid.
  - Must use at least one STL container, different from the one used in Exercise 00.

## Exercise 02

Implement the merge-insert sort algorithm (Ford-Johnson algorithm) to sort a sequence of positive integers.
  - The program `PmergeMe` takes a sequence of positive integers as command-line arguments.
  - It must sort the sequence using the Ford-Johnson algorithm.
  - The implementation must use two different STL containers (e.g., `std::vector` and `std::deque`).
  - The program must display the sequence before and after sorting.
  - It must also display the time taken to sort the sequence with each of the two containers to compare their performance.
  - The containers used must be different from those in the previous exercises.
