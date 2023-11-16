#include  "shell.h"

/**
 * handle_builtin - Handle shell buitin
 * @data: Struct of data
 * Return: 0 on success
 */
int handle_builtin(hsh_t *data)
{
	bul_t built_func[] = {
		{"exit", abort_prg},
		{"cd", change_dir},
		{"help", display_help},
		{NULL, NULL}
	};
	int i = 0;

	while ((built_func + i)->cmd)
	{
		if (_strcmp(data->args[0], (built_func + i)->cmd) == 0)
			return ((built_func + i)->f(data));
		i++;
	}
	return (FAIL);
}
