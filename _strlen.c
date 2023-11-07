#include "main.h"

/**
 * _strlen - Gets the lengnt of a string asides ending null character
 * @str: string to claculate its lenght
 *
 * Return: lenght of string
 */
size_t _strlen(const char *str)
{
	size_t len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}
