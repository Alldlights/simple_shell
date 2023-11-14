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
