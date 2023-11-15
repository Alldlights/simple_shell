#include "shell.h"

/**
* read_line - Read a line from the stdin
* @lineptr: Pointer to the line buffer
* @len: Size of the line buffer
* Return: Number of characters read
*/
ssize_t read_line(char **lineptr, size_t *len)
{
	return (getline(lineptr, len, stdin));
}

/**
 * run_int_mode - Run Interactive mode in Shell
 * Return: Nothing
 */
void run_int_mode(void)
{
	char *lineptr = NULL, *line_cp = NULL;
	char **array;
	ssize_t nchar_read;
	size_t len = 0;
	int exit_status;

	while (1)
	{
		prt_str("($) ");
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
			continue;
		}
		if (is_exit_cmd(array[0]))
		{
			exit_status = exe_exit_cmd(array);
			free(lineptr);
			free(array);
			exit(exit_status);
		}
		else if (is_env_cmd(array[0]))
			exe_env_cmd(array);
		else
			forkexe(array);
	}
}

/**
 * run_non_int - Run the shell in a non interactive mode
 * Return: Nothing
 */
void run_non_int(void)
{
	char *lineptr = NULL, *line_cp = NULL;
	char **array;
	ssize_t nchar_read;
	size_t len = 0;
	int exit_status;

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
		return;
	}
	if (is_exit_cmd(array[0]))
	{
		exit_status = exe_exit_cmd(array);
		free(lineptr);
		free(array);
		exit(exit_status);
	}
	else if (is_env_cmd(array[0]))
		exe_env_cmd(array);
	else
		forkexe(array);
	free(lineptr);
	free(array);
}
