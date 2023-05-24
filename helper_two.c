#include "main.h"

/**
 * get_pid - Gets the current process ID.
 * Return: the current process ID or null if fails.
 */

char *get_pid(void)
{
	size_t i = 0;
	char *buffer;
	ssize_t file;

	file = open("/proc/self/stat", O_RDONLY);
	if (file == -1)
	{
		perror("Cant read file");
		return (NULL);
	}
	buffer = malloc(120);
	if (!buffer)
	{
		close(file);
		return (NULL);
	}
	read(file, buffer, 120);
	while (buffer[i] != ' ')
		i++;
	buffer[i] = '\0';

	close(file);
	return (buffer);
}

/**
 * get_env_value - gets the value.
 * @beginning: variable to search.
 * @length: the length.
 * Return: empty otherwise the value.
 */

char *get_env_value(char *beginning, int length)
{
	/* A pointer to store the address of the environment variable */
	char **var_addr;
	/**
	 * Three pointers to store the value of the environment variable,
	 * a temporary pointer and a copy of the variable name
	 */
	char *replacement = NULL, *temp, *var;

	/* Allocate memory for the copy of the variable name */
	var = malloc(length + 1);
	if (!var)
		return (NULL); /*Return NULL if allocation fails*/
	var[0] = '\0'; /* Initialize the copy to an empty string */
	/* Concatenate the variable name to the copy */
	_strncat(var, beginning, length);

	/* Get the address of the environment variable that matches the copy */
	var_addr = _getenv(var);
	free(var); /*Free the copy*/
	if (var_addr)/*If the address is not NULL*/
	{
		temp = *var_addr; /* Set the temporary pointer to point to the address*/
		while (*temp != '=') /*Loop until reaching the equal sign*/
			temp++; /*Move to the next character*/
		temp++; /*Move past the equal sign*/
		/* Allocate memory for the value of the environment variable */
		replacement = malloc(_strlen(temp) + 1);
		if (replacement)
			/* Copy the value to the replacement pointer */
			_strcpy(replacement, temp);
	}

	return (replacement);/*Return the replacement pointer or NULL if not found*/
}

/**
 * variable_replacement - variable replacer
 * @line: a double pointer containing the command
 * @exe_ret: return value
 */

void variable_replacement(char **line, int *exe_ret)
{
	int j, k = 0, len;
	char *replacement = NULL, *old_line = NULL, *new_line;

	old_line = *line;
	for (j = 0; old_line[j]; j++)
	{
		if (old_line[j] == '$' && old_line[j + 1] &&
			old_line[j + 1] != ' ')
		{
			if (old_line[j + 1] == '$')
			{
				replacement = get_pid();
				k = j + 2;
			}
			else if (old_line[j + 1] == '?')
			{
				replacement = _itoa(*exe_ret);
				k = j + 2;
			}
			else if (old_line[j + 1])
			{
				/* extract the variable name to search for */
				for (k = j + 1; old_line[k] &&
								old_line[k] != '$' &&
								old_line[k] != ' ';
					 k++)
					;
				len = k - (j + 1);
				replacement = get_env_value(&old_line[j + 1], len);
			}
			new_line = malloc(j + _strlen(replacement) + _strlen(&old_line[k]) + 1);
			if (!line)
				return;
			new_line[0] = '\0';
			_strncat(new_line, old_line, j);
			if (replacement)
			{
				_strcat(new_line, replacement);
				free(replacement);
				replacement = NULL;
			}
			_strcat(new_line, &old_line[k]);
			free(old_line);
			*line = new_line;
			old_line = new_line;
			j = -1;
		}
	}
}
