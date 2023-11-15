#include "shell.h"

/**
 * free_array - Free mem allocated for ana rray of str
 * @array: Array of strings
 * Return: Nothing
 */
void free_array(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
}

/**
 * execute_command - Execute a command using execve
 * @command: Array of string denoting command
 * Return: Nothing
 */
void execute_command(char **command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(command[0], command, NULL) == -1)
		{
			write_error("./shell: No such file or directory\n");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		write_error("Fork failed\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}

/**
 * exe_shell - Execute shell
 * Return: Nothing
 */
void exe_shell(void)
{
	char *lineptr = NULL, *line_cp = NULL, *token = NULL;
	char *array[50];
	ssize_t nchar_read;
	size_t len = 0;
	int i;

	while (1)
	{
		print_prompt();
		nchar_read = getline(&lineptr, &len, stdin);
		if (nchar_read == -1)
		{
			write_error("Exiting shell\n");
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		line_cp = _strdup(lineptr);
		for (i = 0; i < 50; i++)
		{
			array[i] = NULL;
		}
		i = 0;
		token = strtok(line_cp, " \n");
		while (token != NULL && i < 50 - 1)
		{
			array[i++] = _strdup(token);
			token = strtok(NULL, " \n");
		}
		if (array[0] != NULL)
			execute_command(array);
		free_array(array);
		free(line_cp);
	}
	free(lineptr);
}
