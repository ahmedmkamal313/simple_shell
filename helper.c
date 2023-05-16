#include "main.h"

/**
 * free_args - frees the memory allocated for a null-terminated array of strings.
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
	/* Declare three variables to store the previous,
	 * current and next characters in the line */
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
