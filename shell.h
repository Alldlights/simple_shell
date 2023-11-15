#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/types.h>

#define PATH_MAX_LENGHT 4096
#define BUFFER_SIZE 1024

extern char **environ;

void print_prompt(void);
void execmd(char **cmd);
size_t _strlen(const char *s);
ssize_t read_line(char **lineptr, size_t *len);
char **tok_str(char *line);
void forkexe(char **cmd);
char *_strcpy(char *dest, const char *src);
char *get_path(void);
void write_error(const char *msg);
char *con_path(const char *path, const char *cmd);
char *find_cmd_in_path(const char *cmd);
char *_strdup(const char *s);
char *_getenv(const char *name);
int _strncmp(const char *fir_str, const char *sec_str, size_t n);
void *_memcpy(void *dest, const void *src, size_t n);
int is_exit_cmd(const char *cmd);
int exe_exit_cmd(char **args);
int _strcmp(const char *fir_str, const char *sec_str);
int is_env_cmd(const char *cmd);
void exe_env_cmd(char **args);
int _atoi(char *str);
int unset_env_var(const char *variable);
int set_env_var(const char *variable, const char *value);
void prt_str(char *msg);
void run_non_int(void);
void run_int_mode(void);
void exe_shell(void);
void free_array(char **array);
void execute_command(char **command);

#endif /* SHELL_H */
