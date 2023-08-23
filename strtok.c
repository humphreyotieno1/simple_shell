#include "shell.h"

/**
 * _free - free a double char pointer
 * @list: the double char pointer
 * @count: the number of single char pointers to free
 */
void _free(char **list, int count)
{
	for (; count >= 0; count--)
		free(list[count]);
	free(list);
}

/**
 * word_count - count number of words in a string
 * @str: string with words
 * @delim: delimiter char
 * Return: number of words
 */

size_t word_count(const char *str,const char *delim)
{
	size_t count = 0;
	int in_word = 0;

	while (*str != '\0')
	{
		if (strchr(delim, *str) != NULL)
		{
			in_word = 0;
		}
		else if(!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

/**
 * _strtok - split a string into a double char pointer
 * @str: the string to split
 * @delim: any characters to split the string by
 * Return: the double char pointer
 */
char **_strtok(char *str,const char *delim)
{
	int i = 0, j = 0, d = 0, len = 0, count = 0, check = 0;
	char **list = NULL;

	/* get count of words, if no words return NULL */
	while (!(count = word_count(str, delim)))
		return (NULL);
	list = do_mem((count + 1) * sizeof(char *), 0);
	if (!list)
		return (NULL);
	/* tokenize str to individual words inside a double pointer*/
	for (i = 0, len = 0, count = 0; str[i] || len;)
	{
		for (d = 0, check = 0; delim[d]; d++)
		{
			if (((str[i] == delim[d]) || (!str[i])))
			{
				check += 1;
				if (len)
				{
					list[count] = do_mem(sizeof(char) * (len + 1), 0);
					if (!list[count])
					{
						_free(list, count);
						return (NULL);
					}
					for (j = 0; len; len--, j++)
						list[count][j] = str[i - len];
					list[count][j] = '\0';
					count++;
				}
			}

		}
		if (!check)
			len++;
		if (str[i])
			i++;
	}
	list[count] = NULL;
	return (list);
}
