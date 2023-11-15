#include "shell.h"

/**
 * _atoi - Converts a string to an integer
 * @str: The string to convert
 * Return: The converted string
 */
int _atoi(char *str)
{
	int result = 0, sign = 1, i = 0;

	while (str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i++] == '-') ? -1 : 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

/**
 * set_env_var - Set or modify an environment variable
 * @variable: Name of the environment variable
 * @value: Value to set fr the environment variable
 * Return: 0 on success, -1 on failure
 */
int set_env_var(const char *variable, const char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		write_error("Failed to set environment variable\n");
		return (-1);
	}
	return (0);
}

/**
 * unset_env_var - Unset an environment variable
 * @variable: Name of the variable to unset
 * Return: 0 on success, -1 on failure
 */
int unset_env_var(const char *variable)
{
	if (unsetenv(variable) != 0)
	{
		write_error("Failed to unset environment variable\n");
		return (-1);
	}
	return (0);
}

/**
 * prt_str - Write a string to the std out
 * @msg: message to write
 * Return: Nothing
 */
void prt_str(char *msg)
{
	write(STDOUT_FILENO, msg, _strlen(msg));
}
