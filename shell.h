#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

#define BUFSIZE 256
#define TOKENSIZE 64
#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define PROMPT "($) "
#define SUCCESS (1)
#define FAIL (-1)
#define NEUTRAL (0)

/**
 * struct hsh_data - Global data structure for the shell
 * @line: The line input
 * @args: Arguments passed
 * @err_msg: The error message
 * @cmd: The parsed command
 * @oldpwd: The old path
 * @index: the index of the command
 * @env: The environment of the shell
 *
 * Description: A structure of all the variables needed to manage the
 * simple shell program, memory and its accessability
 */
typedef struct hsh_data
{
	char *line;
	char **args;
	char *err_msg;
	char *cmd;
	char *oldpwd;
	char *env;
	unsigned long int index;
} hsh_t;

/**
 * struct builtin - Manage the buitin functions
 * @cmd: The command
 * @f: The associated function
 *
 * Desccription: This struct handles the builtin functions
 */
typedef struct builtin
{
	char *cmd;
	int (*f)(hsh_t *data);
} bul_t;

ssize_t read_line(hsh_t *);
int split_line(hsh_t *);
int parse_line(hsh_t *);
int process_cmd(hsh_t *);

char *_strdup(char *str);
char *_strcat(char *first, char *second);
size_t _strlen(char *str);
char *_strchr(char *str, char c);
int _strcmp(char *str, char *str1);
char *_strcpy(char *dest, char *src);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memset(char *s, char byte, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int i);
int free_data(hsh_t *);

void *fill_an_array(void *a, int elem, unsigned int len);
void signal_handler(int signo);
char *_getenv(char *path_name);
void index_cmd(hsh_t *data);
void array_rev(char *arr, int len);

char *_itoa(unsigned int n);
int intlen(int num);
int _atoi(char *c);
int print_error(hsh_t *data, char *name);
int write_history(hsh_t *data);
int _isalpha(int c);

int abort_prg(hsh_t *);
int change_dir(hsh_t *);
int display_help(hsh_t *);
int handle_builtin(hsh_t *);
int check_builtin(hsh_t *);

int is_path_form(hsh_t *);
void is_short_form(hsh_t *);
int is_builtin(hsh_t *);

void interactive(hsh_t *, char **av);
int non_int(hsh_t *, int ac, char **av);
int parse_args(hsh_t *, int ac, char **av);
#endif /* SHELL_H */

