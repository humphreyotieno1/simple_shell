#include "shell.h"

/**
 * tokenize_input - tokenize the input line into an array of arguments
 * @input: input line to be tokenized
 * @argv_ptr: pointer to store dynamically allocated array of arguments
 * Return: number of tokens found
 */
int tokenize_input(char *input, char ***argv_ptr)
{
	const char *delim = " \n";
	int num_tokens = 0;
	char *token = strtok(input, delim);
	char **argv = NULL;
	int i;

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	argv = (char **)malloc(sizeof(char *) * (num_tokens + 1));
	if (argv == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	argv[num_tokens] = NULL;
	*argv_ptr = argv;
	return (num_tokens);
}

/**
 * free_argv - free memory allocated for array of arguments
 * @argv: array of strings containing arguments to be freed
 *
void free_argv(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
}*/
