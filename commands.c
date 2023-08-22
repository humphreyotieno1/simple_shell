#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * execute_command - function to execute the command in the specified argv
 * @argv: array of strings containing commands and arguments
 */

void execute_command(char **argv)
{
	char *command = argv[0];

	if (access(command, X_OK) == 0)
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

			execve(command, argv, environ);
			perror("Command not found");
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
				perror("Child process exited");
			}
		}
	}
	else
	{
		fprintf(stderr, "Command not found: %s\n", command);
	}
}


/**
 * is_builtin_command - check if a command is builtin
 * @command: command to check
 * Return: 1 if builtin, otherwise 0
 */


int is_builtin_command(const char *command)
{
	return (strcmp(command, "cd") == 0 || strcmp(command, "exit") == 0);
}

/**
 * handle_builtin_command - handle execution of builtin commands
 * @argv: array of strongs containing arguments
 */

void handle_builtin_command(char **argv)
{
	if (strcmp(argv[0], "cd") == 0)
	{
		if (argv[1] == NULL)
		{
			fprintf(stderr, "Usage: cd <directory>\n");
		}
		else if (chdir(argv[1]) != 0)
			perror("cd");
		else if (strcmp(argv[0], "exit") == 0)
		{
			exit(0);
		}
		else
			fprintf(stderr, "Unkown command: %s\n", argv[0]);
	}
}

