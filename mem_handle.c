#include "shell.h"

/**
 * _realloc - Reallocates memeory block
 * @ptr: Previous memory
 * @old_size: Previous memory size
 * @new_size: New memory size to be allocated
 * Return: Newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *alloc;

	if (new_size == old_size)
	{
		return (ptr);
	}
	else if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	alloc = malloc(new_size);
	if (alloc == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(alloc, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(alloc, ptr, old_size);
		free(ptr);
	}
	return (alloc);
}

/**
 * _memset - Fills a memory with constant bytes
 * @s: pointer to memory area
 * @n: First n byte
 * @byte: Const bytes
 * Return: Character pointer
 */
char *_memset(char *s, char byte, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = byte;
	}
	return (s);
}

/**
 * free_data - Frees a data
 * @data: Struct of data
 * Return: Positive integer on success, else negative
 */
int free_data(hsh_t *data)
{
	free(data->line);
	data->line = NULL;
	free(data->args);
	data->args = NULL;
	free(data->cmd);
	data->cmd = NULL;
	free(data->err_msg);
	data->err_msg = NULL;
	return (0);
}

/**
 * _memcpy - Copies a memory area
 * @dest: Destination memory area
 * @src: Sorce memory area
 * @i: Amount of memory byte to copy
 * Return: Destination memory area
 */
char *_memcpy(char *dest, char *src, unsigned int i)
{
	unsigned int n;

	for (n = 0; n < i; n++)
	{
		dest[n] = src[n];
	}
	return (dest);
}

