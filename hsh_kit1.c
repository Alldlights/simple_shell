#include "shell.h"

/**
 * _itoa - Convert int to an array
 * @n: The int to convert
 * Return: Converted array of strings
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}

/**
 * _atoi - Converts a character to an integer
 * @c: Character to comvert
 * Return: Integer
 */
int _atoi(char *c)
{
	unsigned int val = 0;
	int sign = 1;

	if (c == NULL)
		return (0);
	while (*c)
	{
		if (*c == '-')
			sign *= (-1);
		else
			val = (val * 10) + (*c - '0');
		c++;
	}
	return (sign * val);
}

/**
 * intlen - Determines the number of digits lenght
 * @num: Number
 * Return: Lenght of integer
 */
int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
 * print_error - Prints an Error msg
 * @data: Struct of data
 * @name: name of executable file
 * Return: positive num on success
 */
int print_error(hsh_t *data, char *name)
{
	char *index_ = _itoa(data->index);

	PRINT(name);
	PRINT(": ");
	PRINT(index_);
	PRINT(data->args[0]);
	PRINT(": ");
	PRINT(data->err_msg);
	free(index_);
	return (0);
}

/**
 * write_history - Prints error
 * @data: Struct of data
 * Return: Positive int on success
 */
int write_history(hsh_t *data)
{
	char *filename = "history";
	char *line_his = "this is a line of history";
	ssize_t fd, w;
	int len;
	(void)data;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDWR | O_APPEND);
	if (fd < 0)
		return (-1);
	if (line_his)
	{
		while (line_his[len])
			len++;
		w = write(fd, line_his, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}
