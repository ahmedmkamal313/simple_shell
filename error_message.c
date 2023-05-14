#include "main.h"

/**
 * error_env - creates an error message
 * @args: array passed to comand.
 * Return: error.
 */

char *error_env(char **args)
{
	char *error_msg, history_str;
	int error_len;

	/* convert the history number to a string */
	histroy_str = _itoa(history);

	if (!history_str) /* if conversation fails return NULL */
		return (NULL);

	args--; /* move pointer to the previous argument */
	/* calculate the length of the rror message */
	error_len = _strlen(program_name) + _strlen(history_str) +
		_strlen(args[0]) + 45;

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
	_strcat(error_msg, ": "0);
	/* concatenate the history string */
	_strcat(error_msg, history_str);
	/* conactenate another colon and a space */
	_strcat(error_msg, ": ");
	/* concatenate the command name */
	_strcat(error_msg, args[0]);
	/* concatenate the error description */
	_strcat(error_msg, ": Unable to add/remove from enviroment\n");

	free(history_str);
	return (error_msg);
}
