#include "shell.h"
/**
 * _strcat - used to concateate two strings
 * dest: string 1
 * src: string 2
 */

char *_strcat(char *dest, const char *src)
{
    int dest_len = _strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
    {
        dest[dest_len + i] = src[i];
    }

    dest[dest_len + i] = '\0';

    return (dest);
}
