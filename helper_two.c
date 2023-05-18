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
	/* A pointer to store the address of the environment variable */
	char **var_addr;
	/**
	 * Three pointers to store the value of the environment variable,
	 * a temporary pointer and a copy of the variable name
	 */
	char *replacement = NULL, *temp, *var;

	/* Allocate memory for the copy of the variable name */
	var = malloc(len + 1);
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
		tem++; /*Move past the equal sign*/
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
	/**
	 * Three variables to store the loop index,
	 * the start index and the size of the line
	 */
	int i, start = 0, size;
	/**
	 * Three pointers to store the substitute value,
	 * the old input line and the new input line
	 */
	char *substitute = NULL, *old_input = NULL, *new_input;

	old_input = *line; /*Set the old input pointer to point to the line*/
	/*Loop through all the characters in the old input*/
	for (i = 0; old_input[i]; i++)
	{
		if (old_input[i] == '$' && old_input[i + 1] && old_input[i + 1] != ' ')
		{
			/*Get the substitute value for the variable name after the dollar sign*/
			substitute = get_substitute(old_input, exe_ret, &i, &start);
			/*Allocate memory for the new input line*/
			new_input = malloc(i + _strlen(substitute) +
					_strlen(&old_input[start]) + 1);
			if (!input)
			return; /*Return if allocation fails*/
			new_input[0] = '\0'; /*Initialize the new input to an empty string*/
			_strncat(new_input, old_input, i);
			if (substitute) /*If there is a substitute value*/
			{
				/*Concatenate the substitute value to the new input*/
				_strcat(new_input, substitute);
				free(substitute); /*Free the substitute pointer*/
				substitute = NULL; /*Set it to NULL*/
			}
			_strcat(new_input, &old_input[start]);
			free(old_input); /*Free the old input pointer*/
			*line = new_input; /* Set the line pointer to point to the new input*/
			old_input  = new_input; /*Set the old input to point to the new input*/
			i = -1; /*Reset the loop index*/
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
		substitute = get_pid(); /*get the process ID as a string*/
		*start = *i + 2;
	}
	else if (old_input[*i + 1] == '?')
	{
		substitute = _itoa(*exe_ret); /*get the exit status of last command */
		*start = *i + 2;
	}
	else if (old_input[*i + 1])
	{
		/* find the end of the environment variable name */
		for (*start = *i + 1; old_input[*start] && old_input[*start] != '$' &&
				old_input[*start] != ' '; (*start)++)
			;
		size = *start - (*i + 1);
		/* get the value of the environment variable */
		substitute = get_env_value(&old_input[*i + 1], size);
	}
	return (substitute);
}
