#include "shell.h"

/**
* is_exit_cmd - Check if the command is the built-in exit cmd
* @cmd: The command to check
* Return: 1 if it is an exit command, 0 otherwise
*/
int is_exit_cmd(const char *cmd)
{
	return (_strcmp(cmd, "exit") == 0);
}

/**
* exe_exit_cmd - Execute the exit built-in cmd to exit shell
* @args: Array of arguments
* Return: Exit status
*/
int exe_exit_cmd(char **args)
{
	char *msg = "Exiting shell...\n";
	int exit_status;

	if (args[1] != NULL)
	{
		exit_status = _atoi(args[1]);
		return (exit_status);
	}
	else
	{
		write(STDOUT_FILENO, msg, _strlen(msg));
		exit(EXIT_SUCCESS);
	}
}

/**
* is_env_cmd - Checks if command is built-in env cmd
* @cmd: command to check
* Return: 1 if it is the env cmd, otherwise 0
*/
int is_env_cmd(const char *cmd)
{
	return (_strcmp(cmd, "env") == 0);
}

/**
* exe_env_cmd - Execute the env built-in command
* which prints the environment variable
* @args: Array of arguments
* Return: Nothing
*/
void exe_env_cmd(char **args)
{
	char **env;

	if (args[1] == NULL)
	{
		for (env = environ; *env != NULL; ++env)
		{
			write(STDOUT_FILENO, *env, _strlen(*env));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	else if (_strcmp(args[1], "setenv") == 0)
	{
		if (args[2] != NULL && args[3] != NULL)
		{
			if (set_env_var(args[2], args[3]) == 0)
				prt_str("Environment var set success\n");
		}
		else
			write_error("Usage: env setenv <variable> <value>\n");
	}
	else if (_strcmp(args[1], "unsetenv") == 0)
	{
		if (args[2] != NULL)
		{
			if (unset_env_var(args[2]) == 0)
				prt_str("Environment var unset success\n");
			else
				write_error("Failed to unset env variable\n");
		}
		else
			write_error("Usage: env unsetenv <variable>\n");
	}
	else
		forkexe(args);
}
