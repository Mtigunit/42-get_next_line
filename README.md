# Get Next Line

<p align="center" > 
	<img src="125.png" width="207" />
</p>

Summary:
This project is about programming a function that returns a line read from a file descriptor.
## Contents

- [Goals](#goals)
- [Common Instructions](#common-instructions)
- [Mandatory Part](#mandatory-part)
- [Bonus Part](#bonus-part)
- [Submission and Peer-Evaluation](#submission-and-peer-evaluation)

## Goals

This project will not only allow you to add a very convenient function to your collection, but it will also make you learn a highly interesting new concept in C programming: static variables.

## Mandatory Part

Function name: `get_next_line`

Prototype: `char *get_next_line(int fd);`

Turn in files: `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`

Parameters: `fd` - The file descriptor to read from

Return value:
- Read line: correct behavior
- NULL: there is nothing else to read, or an error occurred

External functions: `read`, `malloc`, `free`

Description:
Write a function that returns a line read from a file descriptor.
- Repeated calls (e.g., using a loop) to your `get_next_line()` function should let you read the text file pointed to by the file descriptor, one line at a time.
- Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.
- The returned line should include the terminating `\n` character, except if the end of file was reached and does not end with a `\n` character.
- Your header file `get_next_line.h` must at least contain the prototype of the `get_next_line()` function.
- Add all the helper functions you need in the `get_next_line_utils.c` file.

## Bonus Part

- Develop `get_next_line()` using only one static variable.
- Your `get_next_line()` can manage multiple file descriptors at the same time.
