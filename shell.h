#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <stdbool.h>

/**
 * struct list - singly linked list
 * @ptr: a malloced address
 * @next: points to the next node
 * Description: singly linked list node structure
 *
 */

typedef struct list
{
	void *ptr;
	struct list *next;
} list_t;

extern char **environ;
void free_argv(char **argv);
int tokenize_input(char *input, char ***argv_ptr);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strdup(char *str);
int _strlen(char *s);
void my_putchar(char c);
ssize_t else_handle_input(char *lineptr, int stream, char *input, int filled);
int setenv_builtin(char **tokens);
int unsetenv_builtin(char **tokens);
void my_error(const char *command, int code, const char *arg);
int word_count(char *str, char *delim);
int cd_builtin(char **tokens);
char **get_builtins();
int env_builtin(void);
void handle_builtin_command(char **argv);
int is_builtin_command(const char *command);
void prompt_shell(void);
void *do_mem(size_t size, int value);
char **get_env(void);
void free_double_array(char **array);
void do_env(const char *new_variable, const char *old_variable);
char *get_env_val(const char *variable_name);
ssize_t _getline(char *lineptr, int stream);
int has_newline(const char *str);
void shiftbuffer(char *buffer, int start, int length);
void execute_command(char **argv);
char *get_location(char *command);
#endif /* SHELL_H */
