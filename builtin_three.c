#include "main.h"

/**
 * shellby_env - prints the current environment
 * variables to the standard output.
 * @args: array of arguments.
 * @front: pointer to the beginning of args
 * Return: -1 if error , 0
 */

int shellby_env(char **args, char __attribute__((__unused__)) **front)
{
	int index; /* loop variable */
	char nc = '\n'; /* new line character */

	if (!environ) /** if the enviroment array is empty return -1 */
		return (-1);
	/* loop through the enviroment array */
	for (index = 0; environ[index]; index++)
	{
		/* write each variable to the standard output */
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		/* write a newline character after each variable */
		write(STDOUT_FILENO, &nc, 1);
	}

	/* cast args to void to avoid unused parapmeter warning */
	(void)args;
	return (0); /* return 0 on success */
}

/**
 * shellby_setenv - sets or updates an environment variable
 * in the shell environment
 * @args: array of arguments.
 * @front: pointer to the beginning of args.
 * Return: -1 if error , 0.
 */

int shellby_setenv(char **args, char __attribute__((__unused__)) **front)
{
	/* pointers to the env variable new env array and the new value */
	char **env_var = NULL, **new_environ, *new_value;

	size_t size;/* the size of the current enviroment */
	int index; /* loop variable */

	/* if no argument or only one argument is given return error */
	if (!args[0] || !args[1])
		return (create_error(args, -1));
	/* allocate memory for the new value */
	new_value = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!new_value)/* if allocation fails, return an error */
		return (create_error(args, -1));
	_strcpy(new_value, args[0]); /* copy the name to new value */
	_strcat(new_value, "="); /*append an equal sign to the new value*/
	_strcat(new_value, args[1]);/* append the value the new value */
	/* get the pointer to the env variable to bet set or update */
	env_var = _getenv(args[0]);
	if (env_var) /* if the variable already exists */
	{
		free(*env_var); /* free it's memory */
		*env_var = new_value; /* assign the new value to it */
		return (0); /* return 0 on success */
	}
	/* count the number of environment variables */
	for (size = 0; environ[size]; size++)
		;
	/* allocate memory for the new environment array with one extra slot */
	new_environ = malloc(sizeof(char *) * (size + 2));
	if (!new_environ) /* if allocation fails */
	{
		free(new_value); /* free the new value memory */
		return (create_error(args, -1)); /* return an error */
	}
	for (index = 0; environ[index]; index++)
		new_environ[index] = environ[index];
	free(environ); /*free the old environment array*/
	environ = new_environ;
	environ[index] = new_value;
	environ[index + 1] = NULL;
	return (0); /* return 0 on success */
}

/**
 * shellby_unsetenv - removes an environment variable
 * from the shell environment.
 * @args: array of arguments.
 * @front: pointer to the beginning of args.
 * Return: -1 if error , 0.
 */
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var, **new_environ;
	size_t size;
	int index, index2;

	/*if no argument is given, return an error*/
	if (!args[0])
		return (create_error(args, -1));
	env_var = _getenv(args[0]); /*get pointer to the env var to be removed*/
	if (!env_var) /*if the variable does not exist, return 0*/
		return (0);
	/* count the number of environment variables*/
	for (size = 0; environ[size]; size++)
		;
	new_environ = malloc(sizeof(char *) * size);
	if (!new_environ) /*if allocation fails, return an error*/
		return (create_error(args, -1));
	for (index = 0, index2 = 0; environ[index]; index++)
	{
		if (*env_var == environ[index])
		{
			free(*env_var);
			continue;
		}
		new_environ[index2] = environ[index];
		index2++; /* increment the new array index */
	}
	free(environ); /*free the old environment array*/
	environ = new_environ;
	environ[size - 1] = NULL;

	return (0);
}
