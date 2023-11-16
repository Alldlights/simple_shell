#include "shell.h"

/**
 * _strcat - Concatenates two strings with '/'
 * @first: First string
 * @second: second string
 * Return: On success newly concatenated string
 */
char *_strcat(char *first, char *second)
{
	int len1, len2, i = 0, j = 0;
	char *result;

	len1 = _strlen(first);
	len2 = _strlen(second);
	result = malloc((len1 + len2 + 2) * sizeof(char *));
	if (!result)
		return (NULL);
	*result = '\0';
	while (first[j])
		result[i++] = first[j++];
	result[i++] = '/';
	j = 0;
	while (second[j])
		result[i++] = second[j++];
	result[i] = '\0';
	return (result);
}

/**
 * _strlen - Finds the lenght of a string
 * @str: The string
 * Return: The lenght of the string
 */
size_t _strlen(char *str)
{
	size_t len;

	for (len = 0; str[len]; len++)
		;
	return (len);
}

/**
 * _strcmp - Compares two strings
 * @str: First string
 * @str1: Second string
 * Return: 0 on success, else a neagtive number
 */
int _strcmp(char *str, char *str1)
{
	int cmp = 0, i;

	if (str == NULL || str1 == NULL)
		return (1);
	for (i = 0; str[i]; i++)
	{
		if (str[i] != str1[i])
		{
			cmp = str[i] - str1[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
 * _strchr - Locates a character in a string
 * @str: The string
 * @c: The character to locate
 * Return: A pointer to the first occurance of the character
 */
char *_strchr(char *str, char c)
{
	char *ptr;

	if (str == NULL)
		return (NULL);
	for (ptr = str; *ptr; ptr++)
	{
		if (*ptr == c)
			return (ptr);
	}
	return (NULL);
}

/**
 * _strdup - Duplicates a string
 * @str: The strign to be duplicated
 * Return: A pointer to the duplicated string
 */
char *_strdup(char *str)
{
	char *dup;

	if (str == NULL)
		return (NULL);
	dup = malloc(_strlen(str) + 1);
	if (dup == NULL)
		return (NULL);
	_strcpy(dup, str);
	return (dup);
}
