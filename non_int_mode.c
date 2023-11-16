#include "shell.h"

/**
 * non_int - Non-interactive mode of shell handler
 * @data: Struct of data
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int non_int(hsh_t *data, int ac, char **av)
{
	int pl;

	if (parse_args(data, ac, av) < 0)
	{
		free_data(data);
		return (FAIL);
	}
	pl = parse_line(data);
	if (pl == 0)
	{
		free_data(data);
		return (FAIL);
	}
	if (pl < 0)
	{
		print_error(data, av[0]);
		return (FAIL);
	}
	if (process_cmd(data) < 0)
	{
		print_error(data, av[0]);
		return (FAIL);
	}
	free_data(data);
	return (0);
}

/**
 * parse_args - Parse arguments to teh Shell
 * @data: Struct of data
 * @ac: Argument count
 * @av: Argument vector
 * Return: a positive number on succesful execution
 */
int parse_args(hsh_t *data, int ac, char **av)
{
	size_t size = ac + 1, i = 0, j;
	char **tmp;

	data->args = malloc(size * sizeof(char *));
	tmp = malloc(size * sizeof(char *));
	if (tmp == NULL || data->args == NULL)
		return (FAIL);
	while (av[i])
	{
		tmp[i] = av[i];
		i++;
	}
	tmp[i] = NULL;

	for (i = 0, j = 1; tmp[j]; i++, j++)
		data->args[i] = tmp[j];
	data->args[i] = NULL;
	free(tmp);
	return (0);
}
