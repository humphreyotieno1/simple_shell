#include "shell.h"

/**
 * execute_command - function to execute the command in the specified argv
 * @argv: array of strings containing commands and arguments
 */

void execute_command(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *command = argv[0];

		execve(command, argv, NULL);
		perror("Exec error");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);

			printf("Child process exited with status %d\n", exit_status);
		}
		else
		{
			perror("Child process exited abnormally");
		}
	}
}

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
 */
void free_argv(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
}

/**
 * main - entry point of the shell command line
 * Return: 0
 */
int main(void)
{
	char *prompt = "(Shell) $ ";

	char *lineptr = NULL;

	size_t n = 0;

	ssize_t nchars_read;

	char *lineptr_copy = NULL;

	char **argv = NULL;

	int num_tokens = 0;

	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
		{
			printf("Exiting shell....\n");
			break; /*Exit the loop instead of returning -1*/
		}
		lineptr_copy = strdup(lineptr);

		num_tokens = tokenize_input(lineptr_copy, &argv);

		if (num_tokens > 0)
		{
			execute_command(argv);
		}
		free(argv);
		free(lineptr_copy);
	}
	/*Free memory for lineptr*/
	free(lineptr);
	return (0);
}

