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

/**
 * error_exit - create an error message.
 * @args: array passed to command.
 * Return: the error.
 */

char *error_exit(char **args)
{
	char *error_msg, *history_str;
	int error_len;

	/* convert the history number to a string */
	history_str = _itoa(history);
	if (!history_str)
		return (NULL);

	/* calculate the length of the error message */
	error_len = _strlen(program_name) + _strlen(history_str) +
		_strlen(args[0]) + 27;

	/* allocate memory for the error message */
	error_msg = malloc(sizeof(char) * (error_len + 1));
	if (!error_msg)
	{
		free(history_str);
		return (NULL);
	}

	/* copy the program name to the error message */
	_strcpy(error_msg, program_name);
	/* concatenate a colon and a space */
	_strcat(error_msg, ": ");
	_strcat(error_msg, history_str);
	_strcat(error_msg, ": exit: Illegal number: ");
	_strcat(error_msg, args[0]);
	_strcat(error_msg, "\n");

	free(history_str);
	return (error_msg);
}

/**
 * error_cd - create an error message.
 * @args: array passed to command.
 * Return: the error.
 */

char *error_cd(char **args)
{
	char *error_msg, *history_str;
	int error_len;

	/* convert the history number to a string */
	history_str = _itoa(history);
	if (!history_str)
		return (NULL);

	if (args[0][0] == '-')
		args[0][2] = '\0';

	/* calculate the length of the error message */
	error_len = _strlen(program_name) + _strlen(history_str) +
		_strlen(args[0]) + 24;
	/* allocate memory for the error message */
	error_msg = malloc(sizeof(char) * (error_len + 1));
	if (!error_msg)
	{
		free(history_str);
		return (NULL);
	}

	/* copy the program name to the error message */
	_strcpy(error_msg, program_name);
	/* concatenate a colon and a space */
	_strcat(error_msg, ": ");
	_strcat(error_msg, history_str);
	if (args[0][0] == '-')
		_strcat(error_msg, ": cd: Illegal option ");
	else
		_strcat(error_msg, ": cd: can't cd to ");
	_strcat(error_msg, args[0]);
	_strcat(error_msg, "\n");

	free(history_str);
	return (error_msg);
}
