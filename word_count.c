#include "shell.h"

/**
  * word_count - counts the number of words in a string seperated by a delim
  * @str: string to count the words
  * @delim: separator between words
  * Return: number of words
  */
int word_count(char *str, char *delim)
{
	int i, check = 0, count = 0;

	for (i = 0; str && str[i]; i++)
	{
		if ((str[i] == delim[0]) && check)
		{
			count++;
			check = 0;
		}
		else if (str[i] != delim[0])
			check = 1;
	}
	if (str && str[0])
		count++;

	return (count);
}
