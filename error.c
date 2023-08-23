#include "shell.h"

/**
 * my_error - provide a consistent way to display errors
 * @command: string with command where error occurred
 * @code:integer with error code
 * @message: string with additional info about error
 */

void my_error(const char *command, int code, const char *message)
{
	fprintf(stderr, "Error in command '%s' (Error code: %d\n", command, code);
	if (message != NULL)
	{
		fprintf(stderr, "Message: %s\n", message);
	}
}
