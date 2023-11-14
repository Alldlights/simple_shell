#include "shell.h"

/**
 * _getenv - gets the environment variable
 * @name: name of varibale to get it's env
 * Return: a pointer to a string with environment variable
 */
char *_getenv(const char *name)
{
	size_t name_len;
	char **env;

	name_len = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, name_len) == 0 &&
				(*env)[name_len] == '=')
		{
			return (&(*env)[name_len + 1]);
		}
	}
	return (NULL);
}

/**
 * get_path - Get the value of the PATH env variable
 * Return: Value of the PATH env variable
 */
char *get_path(void)
{
	return (_getenv("PATH"));
}

/**
 * con_path - Concatenates two strings with a '/' in between
 * @path: First part of the PATH
 * @cmd: Second part of the PATH
 * Return: Concatenated PATH
 */
char *con_path(const char *path, const char *cmd)
{
	size_t path_len = _strlen(path);
	size_t cmd_len = _strlen(path);
	char *result = malloc(PATH_MAX_LENGHT);

	if (result == NULL)
	{
		write_error("Memeory allocation failed");
		exit(EXIT_FAILURE);
	}
	if (path_len + 1 + cmd_len >= PATH_MAX_LENGHT)
	{
		write_error("Path lenght exceeds limit");
		exit(EXIT_FAILURE);
	}

	_memcpy(result, path, path_len);
	result[path_len] = '/';
	_memcpy(result + path_len + 1, cmd, cmd_len + 1);

	return (result);
}

/**
 * find_cmd_in_path - Search for a command on the dir listed in PATH
 * @cmd: The command to search in the PATH
 * Return: The full path of the command if found, NULL otherwise
 */
char *find_cmd_in_path(const char *cmd)
{
	char *path, *path_cp, *token, *full_path, *abs_path;

	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
		{
			abs_path = _strdup(cmd);
			if (abs_path == NULL)
			{
				write_error("Memory allocation failed");
				exit(EXIT_FAILURE);
			}
			return (abs_path);
		}
		else
			return (NULL);
	}
	path = get_path();
	if (path == NULL)
		return (NULL);
	path_cp = _strdup(path);
	if (path_cp == NULL)
	{
		write_error("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(path_cp, ":");
	while (token)
	{
		full_path = con_path(token, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(path_cp);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_cp);
	return (NULL);
}
