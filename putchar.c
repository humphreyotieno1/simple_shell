#include "shell.h"
#include <errno.h>

/**
 * my_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void my_putchar(char c)
{
	if (putchar(c) == EOF)
	{
		fprintf(stderr, "Error printing character '%c': %s\n", c, strerror(errno));
		exit(EXIT_FAILURE);
	}
}

