# About the CPP Module 06 project

## Summary
The goal of the CPP Module projects is to get familiar with C++ programming language quickly.
This project specifically focuses on `casting`.

>**Allowed:** Any function from the standard library. If there is a C++ version of a function, use that. The code must compile with C++98.
>
>**Forbidden:** Any function from external libraries, as well as `*printf()`, `*alloc()` and `free()`. Containers (`vector`, `list`, `map`, ...) and algorithms (functions from the `algorithm` header).

## Useful Stuff
- [Explicit type conversion, casting](https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/)

## Exercise 00
- Create a class `ScalarConverter` with:
  - A single static method `void convert(std::string literal)`
  - The class must be non-instantiable
- Idendify the type (`char`, `int`, `float`, and `double`) of the literal, convert the string to that type and from that type cast to all others
- Handle:
  - Character literals like `'c'`
  - Float pseudo-literals: `nanf`, `+inff`, `-inff`
  - Double pseudo-literals: `nan`, `+inf`, `-inf`
- Print:
  ```
  char: 'c' / Non displayable / impossible
  int: value / impossible
  float: value.f / nanf
  double: value / nan
  ```

## Exercise 01
- Create a `Serializer` class with:
  - `static uintptr_t serialize(Data* ptr)`
  - `static Data* deserialize(uintptr_t raw)`
- Create a `Data` struct with at least one member
- Test:
  - Create a Data instance, serialize and deserialize it
  - Verify the resulting pointer matches the original one

## Exercise 02
- Create:
  - `Base` class with a virtual destructor
  - Empty classes `A`, `B`, `C` inheriting from `Base`
- Implement:
  - `Base* generate()`: returns randomly created `A`, `B` or `C`
  - `void identify(Base* p)` and `void identify(Base& p)`: prints "A", "B", or "C"
- Do NOT use `std::typeinfo`
