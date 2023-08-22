#include "shell.h"

/**
 * prompt_shell - main loop for shell prompt
 */

void prompt_shell(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	char **argv = NULL;
	int num_tokens = 0;

	while (1)
	{
		printf("(Shell) $ ");
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
		{
			printf("Exiting shell....\n");
			break; /*Exit the loop instead of returning -1*/
		}
		char *lineptr_copy = strdup(lineptr);
		num_tokens = tokenize_input(lineptr_copy, &argv);
		if (num_tokens > 0)
		{
			if (is_builtin_command(argv[0]))
			{
				handle_builtin_command(argv);
			}
			else
			{
				execute_command(argv);
			}
		}
		free(argv);
		free(lineptr_copy);
	}
	free(lineptr);
}
