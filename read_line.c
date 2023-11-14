#include "shell.h"

/**
* read_line - Read a line from the stdin
* @lineptr: Pointer to the line buffer
* @len: Size of the line buffer
* Return: Number of characters read
*/
ssize_t read_line(char **lineptr, size_t *len)
{
	print_prompt();
	return (getline(lineptr, len, stdin));
}
