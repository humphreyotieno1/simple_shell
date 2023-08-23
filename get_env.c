#include "shell.h"

/**
 * get_env - retrieve environment variables
 * Return: pointer to an array of strings with 
 * environment variables
 */

char **get_env(void)
{
	int count = 0;
	char **env;
	int i;

	while (environ[count] != NULL)
	{
		count++;
	}
	env = (char **)do_mem(sizeof(char *) * (count + 1), 0);

	for (i = 0; i < count; i++)
	{
		env[i] = _strdup(environ[i]);
	}
	env[count] = NULL;
	return (env);
}
