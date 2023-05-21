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

