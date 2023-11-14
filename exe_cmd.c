#include "shell.h"

/**
 * execmd - Executea command in a shell
 * @cmd: command to be executed
 * Return:Nothing
 */
void execmd(char **cmd)
{
	char *full_path = find_cmd_in_path(cmd[0]);

	if (full_path == NULL)
	{
		write_error("/hsh: 1: ");
		write_error(cmd[0]);
		write_error(": not found\n");
		exit(EXIT_FAILURE);
	}

	if (execve(full_path, cmd, NULL) == -1)
	{
		write_error(full_path);
		exit(EXIT_FAILURE);
	}
}

/**
 * forkexe - Fork and execute a command
 * @cmd: The command to be executed
 * Return: Nothing
 */
void forkexe(char **cmd)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		write_error("Forking failed");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		execmd(cmd);
	}
	else
	{
		wait(&status);
	}
}
