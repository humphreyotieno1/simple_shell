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

char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strdup(char *str);
int _strlen(char *s);
int _putchar(char c);

#endif /* SHELL_H */
