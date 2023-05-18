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

/**
 * count_tokens - This function takes a string and
 * a delimiter character as arguments.
 * @str: the string.
 * @delim: the delimiter character.
 * Return: the number of tokens.
 */

int count_tokens(char *str, char *delim)
{
	int index = 0;
	int num_tokens = 0;
	int len = 0;

	while (str[index] != '\0')
	{
		len++;
		index++;
	}

	index = 0;

	(index < len)
	{
		if (str[index] != *delim)
		{
			num_tokens++;
			index += token_len(str + index, delim);
		}
		else
		{
			index++;
		}
	}

	return (num_tokens);
}

