# About the CPP Module 00 project

## Summary
The goal of the CPP Module projects is to get familiar with C++ programming language quickly.
- **Allowed functions**: Any function from the standard library, if there is a C++ version of the function, use that. The code must compile with c++98.
- **Forbidden functions**: Any function from external libraries and `*printf()`, `*alloc()` and `free()`.

## Useful Stuff


## Exercise 00
Create a program that behaves like this:
```
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```
- Take any number of arguments
- If no argument given print `* LOUD AND UNBEARABLE FEEDBACK NOISE *` to the STDOUT
- Transform each letter in the input to uppercase and print to the STDOUT

## Exercise 01
Create a phonebook for 8 cantacts
- Implement 2 classes:
	- PhoneBook: an array of contacts, max 8, after reaching max replacing the oldest one
	- Contact: a phonebook contact
- After running the program it will wait for a command
	- **ADD**: to save a new contact with the below mandatory fields (leaving them empty should not be accepted)
		- first name
		- last name
		- nickname
		- phone number
		- darkest secret
	- **SEARCH**: to display the contacts
		- displays 4 columns: index, first name, last name and nickname
		- Columns are 10 char wide *(if longer the 10th char should be a `.`)* separated by `|`
		- The text should be right aligned
		- After displaying prompt for an index.
			- If there is a contact on the given index display the contact information *(1 info per line)*
			- In case of incorect index throw an error and prompt again
	- **EXIT**: to delete the phonebook and exit the program
	- Anything else should just give back the prompt

<div style="background-color: #505050; padding: 10px; border-radius: 5px; font-style: italic;">

Additional things I added that are not in the subject:
- replacing multiple whitespaces with a singular space and trimming the leading and closing whitespaces, if after trimming the string is empty trow an error and prompt again
- for the phone number I only accept numerical value with an optional spaces and a leading `+` sign, but it has to contain at least one number
- if no contact has been saved yet, instead of printing an empty phonebook I throw a `There are no contacts in the phonebook` error and prompt again
- I add the new contact at the top of the phonebook so I don't have to handle the issue when the phonebook is full, bacause the oldest contact is gonna be removed automatically when I have at least 8 contacts already
</div>


## Exercise 02
There is a `test.cpp`, an `Account.hpp` and a log file provided, and using those you have to recreate the missing `Account.cpp` file that should create a program the output of which should be the same as the provided log file *(other than the timestamps)*.