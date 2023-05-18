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
