#include "shell.h"

/**
* print_prompt - Print the shell prompt
* Return: Nothing
*/
void print_prompt(void)
{
	write(STDOUT_FILENO, "($) ", 4);
	fflush(stdout);
}

/**
* write_error - Write an error message to the STDERR
* @msg: The error message to be written
* Return: Nothing
*/
void write_error(const char *msg)
{
	write(STDERR_FILENO, msg, _strlen(msg));
}

/**
* _memcpy - copy memory area;
* @dest: memeory area destination
* @src: memory area source
* @n: number of bytes to copy
* Return: Nothing
*/
void *_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *char_dest = (unsigned char *)dest;
	const unsigned char *char_src = (const unsigned char *)src;
	size_t i;

	for (i = 0; i < n; ++i)
	{
		char_dest[i] = char_src[i];
	}
	return (dest);
}

/**
* _strcmp - compares two string
* @fir_str: Frist string
* @sec_str: second string
* Return: 0 on success
*/
int _strcmp(const char *fir_str, const char *sec_str)
{
	if (fir_str == NULL && sec_str == NULL)
	{
		return (0);
	}
	else if (fir_str == NULL)
	{
		return (-1);
	}
	else if (sec_str == NULL)
	{
		return (1);
	}

	while (*fir_str && (*fir_str == *sec_str))
	{
		fir_str++;
		sec_str++;
	}
	return (*(unsigned char *)fir_str - *(unsigned char *)sec_str);
}
