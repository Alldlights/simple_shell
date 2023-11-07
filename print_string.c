#include "main.h"

/**
 * print_string - Prints a string to the stdout
 * @str : string to print
 *
 * Return: Nothing
 */
void print_string(char *str)
{
	size_t len = _strlen(str);
	write(STDOUT_FILENO, str, len);
}
