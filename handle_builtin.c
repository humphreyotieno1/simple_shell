#include "shell.h"

/**
 * handle_builtin_command - executes a builtin command on provided args
 * @argv: array of strings with the command and its arguments
 */

void handle_builtin_command(char **argv)
{
	if (strcmp(argv[0], "exit") == 0
		exit(0);
	else if (strcmp(argv[0], "cd") == 0
		cd_builtin(argv);
	else if (strcmp(argv[0], "env") == 0
		env_builtin();
	else if (strcmp(argv[0], "setenv") == 0
		setenv_builtin(argv);
	else if (strcmp(argv[0], "unsetenv") == 0
		unsetenv_builtin(argv);
	else
		printf("Command not found: %s\n", argv[0]);
}
