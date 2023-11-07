#include "main.h"

/**
 * main - A program that works like a simple bash shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	(void)argc;
	char *lineptr = NULL,  *lineptr_cp = NULL, *token;
	const char *delim = " \n";
	size_t n = 0;
	ssize_t nchar_read;
	int num_tokens = 0, i, j;

	while (1)
	{
		print_string("$ ");
		nchar_read = getline(&lineptr, &n, stdin);
		if (nchar_read == -1)
		{
			perror("Exiting shell");
			exit(1);
		}
		lineptr_cp = malloc(sizeof(char) * nchar_read);
		if (lineptr_cp == NULL)
		{
			perror("hsh: memory allocation error");
			return (-1);
		}
		_strcpy(lineptr_cp, lineptr);

		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		argv = malloc(sizeof(char *) * num_tokens);
		if (argv == NULL)
		{
			perror("Memory allocation failed");
		}
		token = strtok(lineptr_cp, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * _strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
	}
	free(argv);
	free(lineptr_cp);
	free(lineptr);
	return (0);
}
