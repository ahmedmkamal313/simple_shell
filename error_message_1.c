#include "main.h"

/**
 * error_syntax - creates an error message.
 * @args: array passed to comand.
 * Return: error.
 */

char *error_syntax(char **args)
{
	char *error_msg, *history_str;
	int error_len;

	/* cnvert the history number to a string */
	history_str = _itoa(history);
	if (!history_str)
		return (NULL);

	/* calculate the length of the error message */
	error_len = _strlen(program_name) + _strlen(history_str) +
		strlen(args[0]) + 33;
	error_msg = malloc(sizeof(char) * (error_len + 1));

	if (!error_msg)
	{
		free(history_str);
		return (NULL);
	}

	/* Copy the program name to the error message */
	_strcpy(error_msg, program_name);
	/* concatenate a colon and a space */
	_strcat(error_msg, ": ");
	_strcat(error_msg, history_str);
	_strcat(error_msg, ": Syntax error: \"");
	_strcat(error_msg, args[0]);
	_strcat(error_msg, "\" unexpected\n");

	free(history_str);
	return (error_msg);
}

