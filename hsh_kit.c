#include "shell.h"

/**
 * _getenv - Get the path from the env variable of shell
 * @path_name: Name of path
 * Return: the path called
 */
char *_getenv(char *path_name)
{
	char **env;
	char *env_ptr, *name_ptr;

	env = environ;
	while (*env)
	{
		env_ptr = *env;
		name_ptr = path_name;
		while (*env_ptr == *name_ptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			name_ptr++;
		}
		if ((*env_ptr == '=') && (*name_ptr == '\0'))
		{
			return (env_ptr + 1);
		}
		env++;
	}
	return (NULL);
}

/**
 * signal_handler - Handles the process interrupt signal
 * @signo: The signal identifier
 * Return: void
 */
void signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		PRINT("\n");
		PRINT(PROMPT);
	}
}

/**
 * fill_an_array - Fills an array with elements
 * @a: The array to fill
 * @elem: The elements
 * @len: The lenght of the array
 * Return: Filled array
 */
void *fill_an_array(void *a, int elem, unsigned int len)
{
	char *ptr = a;
	unsigned int i = 0;

	while (i < len)
	{
		*ptr = elem;
		ptr++;
		i++;
	}
	return (a);
}

/**
 * array_rev - Reverse a filled array
 * @array: The array
 * @len: lenght of the array
 * Return: Nothing
 */
void array_rev(char *array, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = array[i];
		array[i] = array[(len - 1) - i];
		array[(len - 1) - i] = tmp;
	}
}

/**
 * index_cmd - Index a command
 * @data: Struct of data
 * Return: void
 */
void index_cmd(hsh_t *data)
{
	data->index += 1;
}
