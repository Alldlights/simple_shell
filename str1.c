#include "shell.h"

/**
 * _strcpy - Copy a string from src to destination
 * @dest: The destination string to copy into
 * @src: The src string
 * Return: The Destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _isalpha - Check if the input is a letter
 * @c: The input to be checked
 * Return: 1 if its a letter, else 0
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (SUCCESS);
	}
	return (FAIL);
}
