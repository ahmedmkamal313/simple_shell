#include "main.h"

/**
 * check_args - checks the validity of the arguments passed to a shell command.
 * @args: the argument of the array.
 * Return: zero if no errors are found.
 */

int check_args(char **args)
{
	size_t i;
	char *current, *next;

	for (i = 0; args[i]; i++)
	{
		current = args[i];
		if (current[0] == ';' || current[0] == '&' || current[0] == '|')
		{
			if (i == 0 || current[1] == ';')
			{
				return (create_error(&args[i], 2));
			}
			next = args[i + 1];
			if (next && (next[0] == ';' || next[0] == '&' || next[0] == '|'))
				return (create_error(&args[i + 1], 2));
		}

	}
	return (0);
}

/**
 * handle_args - handles the arguments passed to a shell command and executes.
 * @exe_ret: the value of executed command.
 * Return: in the off file, if input cannot be tokenized -1
 * exit value.
 */

int handle_args(int *exe_ret)
{
	char *line;
	char **args;
	char **front;
	int i;

	line = get_args(line, exe_ret);

	if (strlen(line) == 0)
		return (-1);

	args = strsplit(line, " ");
	free(line);

	if (args == NULL)
		return (0);
	for (i == 0; args[i] != NULL; i++)
	{
		if (strcmp(args[i], ";") == 0)
		{
			*exe_ret = 2;
			free(args);
			return (*exe_ret);
		}
	}
	front = &args[0];
	for (i = 0; args[i] != NULL; i++)
	{
		if (strcmp(args[i], ";") == 0)
		{
			free(args[i]);
			args[i] = NULL;
			call_and_execute(front, exe_ret);
			front = &args[i + 1];
			i = -1;
		}
	}
	if (args[i] != NULL)
		call_and_execute(front, exe_ret);
	front(front);
	return (*exe_ret);
}

