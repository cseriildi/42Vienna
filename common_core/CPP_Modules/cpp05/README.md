# About the CPP Module 05 project

## Summary
The goal of the CPP Module projects is to get familiar with C++ programming language quickly. 
This project specifically focuses on `exceptions`.

>**Allowed:** Any function from the standard library. If there is a C++ version of a function, use that. The code must compile with C++98.
>
>**Forbidden:** Any function from external libraries, as well as `*printf()`, `*alloc()` and `free()`. Containers (`vector`, `list`, `map`, ...) and algorithms (functions from the `algorithm` header).

## Useful Stuff
- [Video](https://youtu.be/Oy-VTqz1_58?si=Qt9VwNG8TulM8RIv) about exceptions
- [Exceptions, classes, and inheritance](https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/)
- [Uncaught exceptions and catch-all handlers](https://www.learncpp.com/cpp-tutorial/uncaught-exceptions-catch-all-handlers/)

## Exercise 00
- Create class `Bureaucrat` with:
	- `const std::string name`
	- `int grade` (valid range: 1 = highest, 150 = lowest)
- Implement:
	- a function to increment and decrement the grade with range checks
	- Exceptions `GradeTooHighException` and `GradeTooLowException`
	- `<<` operator to print: `<name>, bureaucrat grade <grade>`

## Exercise 01
- Create class `Form` with:
	- `const std::string name`
	- `bool isSigned`
	- `const int gradeToSign` and `const int gradeToExecute`
- Implement:
	- `beSigned(Bureaucrat&)`
	- Overload `<<` to print form status
- Update `Bureaucrat::signForm(Form&)`:
	- Print success/failure messages based on whether signing succeeds

## Exercise 02
- Rename `Form` to `AForm` and make it abstract
- Add classes:
	- `ShrubberyCreationForm`: creates file `<target>_shrubbery` with ASCII trees
	- `RobotomyRequestForm`: has 50% success to robotomize target
	- `PresidentialPardonForm`: prints that target was pardoned
- Implement:
	- `execute(Bureaucrat const&)` in each form
	- `Bureaucrat::executeForm(AForm const&)`

## Exercise 03
- Create class `Intern` with:
	- `makeForm(std::string name, std::string target)` method
- Implement:
	- Returns dynamically created form based on `name`
	- If form type is unknown, print error
	- Avoid long if/else chains
