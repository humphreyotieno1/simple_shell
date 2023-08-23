#include "shell.h"

/**
 * get_env_val - get the value of an environ var
 * @name: name of environ var
 * Return: value of the environ var, NULL if absent
 */

char *get_env_val(const char *name)
{
	char *env_value = getenv(name);
	return (env_value);
}
