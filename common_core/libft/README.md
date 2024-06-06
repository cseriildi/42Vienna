# About the libft project

## Summary
The goal of this project is to create a collection of useful functions, that you can use in your projects later on.

## Useful stuff
- [Playlist to get familiar with linked lists](https://youtube.com/playlist?list=PLfqABt5AS4FmXeWuuNDS3XGENJO1VYGxl&si=ikrLdNy9fU9_zIVJ)

## Mandatory Part

### Libc Functions
These functions are re-creations of existing standard library functions.

- **ft_isalpha**: Checks if a character is an alphabetic letter. (`man isalpha`)
- **ft_isdigit**: Checks if a character is a digit (0-9). (`man isdigit`)
- **ft_isalnum**: Checks if a character is alphanumeric. (`man isalnum`)
- **ft_isascii**: Checks if a character is an ASCII character. (`man isascii`)
- **ft_isprint**: Checks if a character is printable. (`man isprint`)
- **ft_strlen**: Returns the length of a string. (`man strlen`)
- **ft_memset**: Fills a memory block with a specified value. (`man memset`)
- **ft_bzero**: Sets a block of memory to zero. (`man bzero`)
- **ft_memcpy**: Copies memory from one location to another. (`man memcpy`)
- **ft_memmove**: Copies memory from one location to another, handling overlaps. (`man memmove`)
- **ft_strlcpy**: Copies a string to a destination buffer, ensuring null-termination. (`man strlcpy`)
- **ft_strlcat**: Appends a string to a destination buffer, ensuring null-termination. (`man strlcat`)
- **ft_toupper**: Converts a character to uppercase. (`man toupper`)
- **ft_tolower**: Converts a character to lowercase. (`man tolower`)
- **ft_strchr**: Locates the first occurrence of a character in a string. (`man strchr`)
- **ft_strrchr**: Locates the last occurrence of a character in a string. (`man strrchr`)
- **ft_strncmp**: Compares two strings up to a specified number of characters. (`man strncmp`)
- **ft_memchr**: Locates a character in a block of memory. (`man memchr`)
- **ft_memcmp**: Compares two blocks of memory. (`man memcmp`)
- **ft_strnstr**: Locates a substring within a string. (`man strnstr`)
- **ft_atoi**: Converts a string to an integer. (`man atoi`)
- **ft_calloc**: Allocates and initializes memory for an array. (`man calloc`)
- **ft_strdup**: Duplicates a string using dynamic memory allocation. (`man strdup`)

### Additional Functions

- **ft_substr**: Creates a substring from a string.
- **ft_strjoin**: Concatenates two strings into a new string.
- **ft_strtrim**: Trims characters from the beginning and end of a string.
- **ft_split**: Splits a string into an array of strings using a delimiter.
- **ft_itoa**: Converts an integer to a string.
- **ft_strmapi**: Applies a function to each character of a string, creating a new string.
- **ft_striteri**: Applies a function to each character of a string by reference.
- **ft_putchar_fd**: Outputs a character to a file descriptor.
- **ft_putstr_fd**: Outputs a string to a file descriptor.
- **ft_putendl_fd**: Outputs a string followed by a newline to a file descriptor.
- **ft_putnbr_fd**: Outputs an integer to a file descriptor.

## Bonus Part

Basic functions to work with linked lists.

- **ft_lstnew**: Creates a new list node.
- **ft_lstadd_front**: Adds a node to the beginning of a list.
- **ft_lstsize**: Counts the number of nodes in a list.
- **ft_lstlast**: Returns the last node of a list.
- **ft_lstadd_back**: Adds a node to the end of a list.
- **ft_lstdelone**: Deletes a node, using a provided function to free its content.
- **ft_lstclear**: Deletes and frees all nodes of a list.
- **ft_lstiter**: Applies a function to the content of each node in a list.
- **ft_lstmap**: Creates a new list by applying a function to each node of an existing list.
