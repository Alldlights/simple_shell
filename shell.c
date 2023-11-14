#include "shell.h"

/**
 * main - Entry point to shell
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *lineptr = NULL, *line_cp = NULL;
	char **array;
	ssize_t nchar_read;
	size_t len = 0;
	(void)argc, (void)argv;

	while (1)
	{
		nchar_read = read_line(&lineptr, &len);
		if (nchar_read == -1)
		{
			write_error("Exiting Shell\n");
			free(lineptr);
			exit(EXIT_FAILURE);
		}

		line_cp = _strdup(lineptr);
		array = tok_str(line_cp);
		if (array == NULL)
		{
			free(line_cp);
			return (-1);
		}

		if (is_exit_cmd(array[0]))
		{
			exe_exit_cmd();
		}
		else if (is_env_cmd(array[0]))
		{
			exe_env_cmd();
		}
		else
		{
			forkexe(array);
		}
		free(array);
	}
	free(lineptr);
	return (0);
}


