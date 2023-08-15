#include "shell.h"

/**
 * *_strcpy - copy the string pointed by src, to the buffer pointed to by dest
 * @dest: char pointer
 * @src: char pointer 2
 * Return: dest pointer
 */
char *_strcpy(char *dest, char *src)
{
        char *dest_start = dest;

        while (*src != '\0')
        {
                *dest = *src;
                dest++;
                src++;
        }
        *dest = '\0';
        return (dest_start);
}
