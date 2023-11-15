#include "shell.h"

/**
 * main - Entry point to shell
 * Return: 0 on success
 */
int main(void)
{
	exe_shell();
	/**if (isatty(STDIN_FILENO))
	{
		run_int_mode();
	}
	else
	{
		run_non_int();
	}**/
	return (0);
}
