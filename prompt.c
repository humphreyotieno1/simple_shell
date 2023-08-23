#include "shell.h"

/**
 * prompt_shell - main loop for shell prompt
 */

void prompt_shell(void)
{
	char lineptr[4096];
	ssize_t nchars_read;
	char **argv = NULL;
	int num_tokens = 0;
	char *lineptr_copy;

	while (1)
	{
		printf("(Shell) $ ");
		nchars_read = _getline(lineptr, STDIN_FILENO);
		if (nchars_read == -1)
		{
			fprintf(stderr, "Error reading input\n");
			continue;
		}
		if (nchars_read == 0)
		{
			printf("Exiting shell....\n");
			break; /*Exit the loop instead of returning -1*/
		}
		lineptr_copy = strdup(lineptr);
		num_tokens = tokenize_input(lineptr_copy, &argv);
		if (num_tokens > 0)
		{
			if (strcmp(argv[0], "env") == 0)
			{
				char **env_ptr = environ;

				while (*env_ptr != NULL)
				{
					printf("%s\n", *env_ptr);
					env_ptr++;
				}
			}
			else if (is_builtin_command(argv[0]))
				handle_builtin_command(argv);
			else
				execute_command(argv);
		}
		free(argv);
		free(lineptr_copy);
	}
}
