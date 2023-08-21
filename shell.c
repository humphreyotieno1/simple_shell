#include "shell.h"

/**
 * numline - gets and adds line number of current line
 * @add: adds number
 * Return: the line number
 */

int numline(int add)
{
	static int line;

	line = line + add;

	return (line);
}

/**
 * prog_name - gets the name of the program
 * @name: name of the program
 * Return: name of the program
 */

char *prog_name(char *name)
{
	static char *ret;

	if (!ret)
	{
		ret = name;
	}

	return (ret);
}

/**
 * _error - custom error printing
 * @command: the message to print
 * @status: the type of error to print
 * @plus: any additional information
 */

void _error(char *command, int status, char *plus)
{
	char *name = NULL;
	char *line = NULL;
	char *msg = NULL;

	name = prog_name(NULL);
	line = _itoa(numline(0));
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, line, _strlen(line));

	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": ", 2);

	switch (status)
	{
		case 2:
		msg = "not found";
		break;
	case 126:
		msg = "Permission denied";
		break;
	case 127:
		msg = "not found";
		break;
	case 9000:
		msg = "Illegal number: ";
		break;
	default:
		msg = "Unknown error occured.";
	}
	write(STDERR_FILENO, msg, _strlen(msg));

	if (plus)
		write(STDERR_FILENO, plus, _strlen(plus));

	write(STDERR_FILENO, "\n", 1);
}

/**
 * main - simple shell
 * @argc: number of arguments
 * @argv: list of arguments
 * @envp: environment
 * Return: 0 if success
 */

int main(int argc, char **argv, char **envp)
{
	char *filename = NULL;

	prog_name(argv[0]);

	if (argc > 2)
		return (-1);

	if (argv && argv[1])
		filename = argv[1];
	signal(SIGINT,  signal_handler);
	do_env((char *)envp, NULL);

	numline(1);

	main_loop(filename);

	return (0);
}
