#include "shell.h"

/**
 * is_path_form - Checks if the given filename is a path
 * @data: Struct of data
 * Return: Positive value on success, else neagative
 */
int is_path_form(hsh_t *data)
{
	if (_strchr(data->args[0], '/') != 0)
	{
		data->cmd = _strdup(data->args[0]);
		return (SUCCESS);
	}
	return (FAIL);
}
#define DELIMITER ":"
/**
 * is_short_form - Checks if the given pathname is a short form
 * @data: Struct of data
 * Return: Nothing
 */
void is_short_form(hsh_t *data)
{
	char *path, *token, *path_cp;
	struct stat st;
	int exit_flag = 0;

	path = _getenv("PATH");
	path_cp = _strdup(path);
	token = strtok(path_cp, DELIMITER);
	while (token)
	{
		data->cmd = _strcat(token, data->args[0]);
		if (stat(data->cmd, &st) == 0)
		{
			exit_flag += 1;
			break;
		}
		free(data->cmd);
		token = strtok(NULL, DELIMITER);
	}
	if (exit_flag == 0)
	{
		data->cmd = _strdup(data->args[0]);
	}
	free(path_cp);
}
#undef DELIMITER
/**
 * is_builtin - Checks if the command is a builtin
 * @data: Struct of data
 * Return: 0 on success, otherwise a negative number
 */
int is_builtin(hsh_t *data)
{
	bul_t built_func[] = {
		{"exit", abort_prg},
		{"cd", change_dir},
		{"help", display_help},
		{NULL, NULL}
	};
	int i = 0;

	while ((built_func + 1)->cmd)
	{
		if (_strcmp(data->args[0], (built_func + 1)->cmd) == 0)
			return (SUCCESS);
		i++;
	}
	return (NEUTRAL);
}
