#include "shell.h"

/**
 * do_env - set environment variables
 * @name: name of environ var
 * @value: value to set for variable
 * Return: 0 on success, -1 on fail
 */

int do_env(const char *name, const char *value)
{
	if (name == NULL)
	{
		return (-1);
	}
	if (value == NULL)
	{
		char *env_value = getenv(name);

		if (env_value == NULL)
			return (-1);
		printf("%s\n", env_value);
	}
	else
	{
		int result = setenv(name, value, 1);

		if (result != 0)
			return (-1);
	}
	return (0);
}
