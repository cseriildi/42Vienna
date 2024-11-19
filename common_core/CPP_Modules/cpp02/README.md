# About the CPP Module 02 project

## Summary
The goal of the CPP Module projects is to get familiar with C++ programming language quickly. To learn about ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Class Form.
- **Allowed functions**: Any function from the standard library, if there is a C++ version of the function, use that. The code must compile with c++98.
- **Forbidden functions**: Any function from external libraries and `*printf()`, `*alloc()` and `free()`. Namespace and friend keyword. `Containers` (vector/list/map/...) and `Algorithms` (functions from the `algorithm` header).

## Useful Stuff

## Exercise 00
This one is about fixed point numbers.
- Create class `Fixed` with:
	- `private` members:
		- an `int` to store the fixed-point number value
		- a `static const int` to store the number of fractional bits and set it as 8
	- `public` members:
		- default constructor *(sets value to 0)*
		- copy constructor
		- copy assignment operator overload
		- destructor
		- `int getRawBits(void) const;`
		- `void setRawBits(int const raw);`
- Print messages in the functions so you can identify when they get called.

## Exercise 01
Using the same class from previous exercise add:
- parametrized constructor that takes a `const int`, converts it to fixed point number and sets it as the value
- parametrized constructor that takes a `const float`, converts it to fixed point number and  sets it as the value
- `float toFloat(void) const;` converts fixed point number to `float`
- `int toInt(void) const;` converts fixed point number to `int`
- `<<` operation overload function, that inserts a float (converted from the fixed-point number) into the output stream object passed as parameter.

## Exercise 02
Using the same class from previous exercise add:
- operator overload for: 
	- `>`, `<`, `>=`, `<=`, `==`, `!=`, `+`, `-`, `*`, `/`
	- pre/post-increment and pre/post-decrement which should increase decrease by the smallest representable `ϵ` such as `1 + ϵ > 1`.
- static member function:
	- `min` takes 2 fixed point number refrences and returns the smaller one
	- `min` takes 2 const fixed point number refrences and returns the smaller one
	- `max` takes 2 fixed point number refrences and returns the greater one
	- `max` takes 2 const fixed point number refrences and returns the greater one

## Exercise 03
This one is about binary space partitioning and determining if a point is inside a triangle or not using the class from the previous exercise.
- Create class `Point` with:
	- `private` members:
		- Fixed const `x` and `y` for the coordinates
	- `public` members:
		- default constructor *(initialize x and y as 0)*
		- parameterized constructor that takes 2 const floats and initialize `x` and `y` with them.
		- copy constructor
		- copy assignment operator overload
- Implement `bool bsp( Point const a, Point const b, Point const c, Point const point);` function that takes the 3 vertexes of the triangle and a point, returns true if inside, false if outside, on the edge or vertex.
