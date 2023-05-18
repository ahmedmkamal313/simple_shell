#include "main.h"

/**
 * _copyenv - copy the environment variable from the global variable
 * Return: new array of strings with the same values
 * NULL if memory allocation fails
 */

char **_copyenv(void)
{
	/* Declare a pointer to an array of strings for the new env variables */
	char **new_env;
	/*Declare a variable to store the size of the environ array*/
	size_t env_size;
	/* Declare and initialize a variable to store the index of the array*/
	int i;

	/*Loop through the environ array and increment the size by one*/
	for (env_size = 0; environ[env_size]; env_size++)
		;

	/**
	 * Allocate memory for the new array with enough space for
	 * the strings and a NULL pointer
	 */
	new_env = malloc(size(char *) * (env_size + 1));
	if (!new_env) /* if memory allocation fails */
		return (NULL);

	for (i = 0; environ[i]; i++) /*Loop through the environ array again*/
	{
		new_env[i] = malloc(_strlen(environ[i]) + 1);
		if (!new_env[i]) /* If memory allocation fails */
		{
			for (i--; i >= 0; i--) /*Loop through the previous strings*/
				free(new_env[i]); /* Free their memory*/
			free(new_env);
			return (NULL);
		}
		/*Copy each string from the environ array to the new array*/
		_strcpy(new_env[i], environ[i]);
	}
	new_env[i] = NULL;
	return (new_env);
}
