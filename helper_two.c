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

/**
 * variable_replacement - variable replacer
 * @line: a double pointer containing the command
 * @exe_ret: return value
 */

void variable_replacement(char **line, int *exe_ret)
{
	int i, start = 0, size;
	char *substitute = NULL, *old_input = NULL, *new_input;

	old_input = *line;
	for (i = 0; old_input[i]; i++)
	{
		if (old_input[i] == '$' && old_input[i + 1] && old_input[i + 1] != ' ')
		{
			substitute = get_substitute(old_input, exe_ret, &i, &start);
			new_input = malloc(i + _strlen(substitute) +
					_strlen(&old_input[start]) + 1);
			if (!input)
			return;
			new_input[0] = '\0';
			_strncat(new_input, old_input, i);
			if (substitute)
			{
				_strcat(new_input, substitute);
				free(substitute);
				substitute = NULL;
			}
			_strcat(new_input, &old_input[start]);
			free(old_input);
			*line = new_input;
			old_input  = new_input;
			i = -1;
		}
	}
}

/**
 * get_substitute - returns a substitute string for a variable in the input
 * @old_input: the original input string
 * @exe_ret: the execution return value
 * @i: the index of the '$' character in the input
 * @start: the index of the next character after the variable name in the input
 * Return: a pointer to the substitute string, or NULL if none
 */

char *get_substitute(char *old_input, int *exe_ret, int *i, int *start)
{
	char *substitute = NULL;
	int size;

	if (old_input[*i + 1] == '$')
	{
		substitute = get_pid();
		*start = *i + 2;
	}
	else if (old_input[*i + 1] == '?')
	{
		substitute = _itoa(*exe_ret);
		*start = *i + 2;
	}
	else if (old_input[*i + 1])
	{
		for (*start = *i + 1; old_input[*start] && old_input[*start] != '$' &&
				old_input[*start] != ' '; (*start)++)
			;
		size = *start - (*i + 1);
		substitute = get_env_value(&old_input[*i + 1], size);
	}
	return (substitute);
}
