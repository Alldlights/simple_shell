#include "shell.h"

/**
* _strlen - Calculates the lenght of a string
* @s: Sting to get its lenght
* Return: Lenght of string in bytes
*/
size_t _strlen(const char *s)
{
	size_t i = 0;

	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

/**
 * tok_str - Tokenize a string
 * @line: The string to tokenize
 * Return: Array of token
 */
char **tok_str(char *line)
{
	int i = 0;
	char *token;
	char **array = malloc(sizeof(char *) * 1024);

	if (array == NULL)
	{
		write_error("Memory allocation failed");
		return (NULL);
	}

	token = strtok(line, " \n");
	while (token)
	{
		array[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	array[i] = NULL;
	return (array);
}

/**
 * _strdup - Duplicates a string
 * @s: String to duplicate
 * Return: Pointer to the duplicated string
 */
char *_strdup(const char *s)
{
	size_t len;
	char *str_dup;

	if (s == NULL)
	{
		return (NULL);
	}
	len = _strlen(s) + 1;
	str_dup = malloc(len);
	if (str_dup != NULL)
	{
		_strcpy(str_dup, s);
	}
	return (str_dup);
}

/**
 * _strcpy - Copies content of one string to another
 * @dest: string to copy content
 * @src: string to copy from
 * Return: The copied string
 */
char *_strcpy(char *dest, const char *src)
{
	char *org_dest = dest;

	while ((*dest++ = *src++))
	{
		;
	}
	return (org_dest);
}

/**
 * _strncmp - Compares two string
 * @fir_str: First string
 * @sec_str: second string
 * @n: number of bytes to compare the string
 * Return: 0 if string is found, otherwise -1
 */
int _strncmp(const char *fir_str, const char *sec_str, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (fir_str[i] != sec_str[i])
		{
			return ((unsigned char) fir_str[i] - (unsigned char)
						sec_str[i]);
		}
		if (fir_str[i] == '\0')
		{
			break;
		}
	}
	return (0);
}
