#include "shell.h"

/**
 * main - The entry point to the Shell
 * @ac: Argument count
 * @av: argument vector
 * Return: 0 on succes
 */
int main(int ac, char **av)
{
	hsh_t data;
	int pl;

	_memset((void *)&data, 0, sizeof(data));
	signal(SIGINT, signal_handler);

	if (ac >= 2)
	{
		index_cmd(&data);
		pl = non_int(&data, ac, av);
		if (pl < 0)
		{
			free_data(&data);
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	interactive(&data, av);
	exit(EXIT_SUCCESS);
}

/**
 * read_line - Read a line from the stdin
 * @data: Struct of data
 * Return: on success a positive number, negative number otherwise
 */
ssize_t read_line(hsh_t *data)
{
	size_t n = 0;
	ssize_t input;

	if (isatty(STDIN_FILENO))
		PRINT(PROMPT);
	input = getline(&(data->line), &n, stdin);
	if (input < 0)
		return (FAIL);
	return (0);
}
#define DELIMITER " \n\t\r\a\v"
/**
 * split_line - Tokenize a line
 * @data: Struct of data
 * Return: On success a postive number, a negative number otherwise
 */
int split_line(hsh_t *data)
{
	char *token;
	size_t size = TOKENSIZE, new_size, i = 0;

	if (_strcmp(data->line, "\n") == 0)
		return (FAIL);
	data->args = malloc(size * sizeof(char *));
	if (data->args == NULL)
		return (FAIL);
	token = strtok(data->line, DELIMITER);
	if (token == NULL)
		return (FAIL);
	while (token)
	{
		data->args[i++] = token;
		if (i + 2 >= size)
		{
			new_size = size * 2;
			data->args = _realloc(data->args, size * sizeof(char *)
					, new_size * sizeof(char *));
			if (data->args == NULL)
				return (FAIL);
			size = new_size;
		}
		token = strtok(NULL, DELIMITER);
	}
	data->args[i] = NULL;
	return (0);
}
#undef DELIMITER
#define DELIMITER ":"
/**
 * parse_line - Parses argument to a valid command
 * @data: Struct of data
 * Return: On success a positive number, a negative one otherwise
 */
int parse_line(hsh_t *data)
{
	if (is_path_form(data) > 0)
		return (SUCCESS);
	if (is_builtin(data) > 0)
	{
		if (handle_builtin(data) > 0)
			return (FAIL);
		return (NEUTRAL);
	}
	is_short_form(data);
	return (SUCCESS);
}

#undef DELIMITER
/**
 * process_cmd - Process a command and execute
 * @data: Struct of data
 * Return: On success a postive number, otherwise a negative number
 */
int process_cmd(hsh_t *data)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(data->cmd, data->args, environ) < 0)
		{
			data->err_msg = _strdup("not found\n");
			return (FAIL);
		}
	}
	else
	{
		waitpid(child, &status, WUNTRACED);
	}
	return (0);
}
