#include "main.h"

/**
 * token_len - takes a string and a delimiter character as arguments.
 * @str: the string.
 * @delim: the delimiter character.
 * Return: the length of the token.
 */

int token_len(char *str, char *delim)
{
	int index = 0;
	int len = 0;

	while (str[index] != '\0' && str[index] != *delim)
	{
		len++;
		index++;
	}
	return (len);
}
