#include "main.h"

/**
 * get_pid - Gets the current process ID.
 * Return: the current process ID or null if fails.
 */

char *get_pid(void)
{
	int fd, i; /* file descriptor for the stat file*/
	char buf[10]; /* buffer to stor the PID */
	ssize_t bytes; /* number of bytes read from the file */

	/* open the stat file in read-only mode */
	fd = open("/prog/self/stat", O_RDONLY);
	if (fd == -1) /*check if the open failed */
	{
		perror("Can't read file"); /* print an error message */
		return (NULL);
	}
	/* read up to 10 bytes from the file into the buffer */
	bytes = read(fd, buf, 10);
	if (bytes == -1) /* check if the read failed */
	{
		perror("Can't read file"); /* print an error message */
		close(fd); /* close the file descriptor */
		return (NULL);
	}
	close(fd); /* close the file descriptor */
	buf[bytes] = '\0'; /* add null terminator to the end of buffer*/
	/* loop over the buffer */
	for (i = 0; i < bytes; i++)
	{
		if (buf[i] == ' ') /*check if there is a space char */
		{
			/* replace it with a null terminator */
			buf[i] = '\0';
			break;
		}
	}
	return (strdup(buf)); /*return a copy of the buffer as a string*/
}

/**
 * get_env_value - gets the value.
 * @beginning: variable to search.
 * @length: the length.
 * Return: empty otherwise the value.
 */

char *get_env_value(char *beginning, int length)
{

	char **var_addr;
	char *replacement = NULL, *temp, *var;

	var = malloc(len + 1);
	if (!var)
		return (NULL);
	var[0] = '\0';
	_strncat(var, beginning, length);

	var_addr = _getenv(var);
	free(var);
	if (var_addr)
	{
		temp = *var_addr;
		while (*temp != '=')
			temp++;
		tem++;
		replacement = malloc(_strlen(temp) + 1);
		if (replacement)
			_strcpy(replacement, temp);
	}

	return (replacement);
}
