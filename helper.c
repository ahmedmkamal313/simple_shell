#include "main.h"

/**
 * free_args - frees the memory allocated for null-terminated array of strings
 * @args: a pointer to the array of strings.
 * @front: the original pointer to the array of strings.
 */

void free_args(char **args, char **front)
{
	size_t i; /*Declare a variable to loop through the array*/

	/* Loop until reaching either a null pointer or the last element */
	for (i = 0; args[i] || args[i + 1]; i++)
		free(args[i]);

	free(front);
}

/**
 * logical_ops - checks a line for logical operators
 * @line: a pointer to the character to check in the line.
 * @new_len: a pointer to the new len.
 */

void logical_ops(char *line, ssize_t *new_len)
{
	/**
	 * Declare three variables to store the previous,
	 * current and next characters in the line
	 */
	char prev, curr, next;

	/* assign the previous character to prev */
	prev = *(line - 1);
	/* assign the current character to curr */
	current = *line;
	/* assign the next character to next */
	next = *(line + 1);

	if (curr == '&')
	{
		if (next == '&' && prev != ' ')
			(*new_len)++;
		else if (prev == '&' && next != ' ')
			(*new_len)++;
	}
	else if (curr == '|')
	{
		if (next == '|' && prev != ' ')
			(*new_len)++;
		else if (previous == '|' && next != ' ')
			(*new_len)++;
	}
}

/**
 * get_new_len - get the length of a line
 * @line: the checked line.
 * Return: the new length.
 */

ssize_t get_new_len(char *line)
{
	size_t i;
	ssize_t new_len = 0;
	char current, next;

	/* loop through the line until reaching the null term */
	for (i = 0; line[i]; i++)
	{
		current = line[i]; /* assign the current char to current */
		next = line[i + 1]; /*assign the next to next */
		if (current == '#' && (i == 0 || line[i - 1] == ' '))
		{
			line[i] = '\0'; /* replace it will null term */
			break;
		}
		else if (current == ';')
		{
			if ((next == ';' || line[i - 1] == ';')
					&& line[i - 1] != ' ' && next != ' ')
				new_len += 2;
			else
				new_len += (line[i - 1] != ' ') + (next != ' ');
		}
		else
			logical_ops(&line[i], &new_len);
		new_len++;
	}

	return (new_len);
}

