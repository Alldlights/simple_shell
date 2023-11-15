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
	int exit_status;
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
		if (!array)
		{
			free(line_cp);
			return (-1);
		}
		if (isatty(STDOUT_FILENO) && is_exit_cmd(array[0]))
		{
			exit_status = exe_exit_cmd(array);
			free(lineptr);
			free(array);
			exit(exit_status);
		}
		else if (isatty(STDOUT_FILENO) && is_env_cmd(array[0]))
			exe_env_cmd(array);
		else if (isatty(STDOUT_FILENO))
			forkexe(array);
		else
			write_error("Output is not a terminal\n");
		free(array);
	}
	free(lineptr);
	return (0);
}
