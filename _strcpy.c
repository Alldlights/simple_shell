#include "main.h"

/**
 * _strcpy - Copies a string from source to destination
 * @dest: where to copy string to
 * @src: where to copy from
 *
 * Return : destination string
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr;
	if (dest == NULL)
	{
		return (NULL);
	}

	ptr = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}

