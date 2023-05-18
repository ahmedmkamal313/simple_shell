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
	int index;
	int num_tokens = 0;
	int len = 0;

	while (str[index] != '\0')
	{
		len++;
		index++;
	}

	index = 0;

	while (index < len)
	{
		if (str[index] != *delim)
		{
			num_tokens++;
			index += token_len(str + index, delim);
		}

			index++;
	}

	return (num_tokens);
}

/**
 * _strtok -  This function takes a string and a delimiter
 * character as arguments and returns an array of tokens in the string.
 * @line: the string buffer to start the command.
 * @delim: the delimiter character.
 * Return: the array of tokens.
 */

char **_strtok(char *line, char *delim)
{
	char **tokens;
	int i;
	int index = 0, numTokens = 0, tokenIndex = 0, letterIndex = 0;
	int tokenlen;

	numTokens = count_tokens(line, delim);

	if (numTokens == 0)
		return (NULL);
	tokens = malloc((numTokens + 2) * sizeof(char *));

	if (tokens == NULL)
		return (NULL);
	while (tokenIndex < numTokens)
	{
		while (line[index] == *delim)
			index++;
		tokenlen = token_len(line, delim, index);
		tokens[tokenIndex] = (char *)malloc((tokenLen + 1)sizeof(char));

		if (tokens[tokenIndex] == NULL)
		{
			for (i = 0; i < tokenIndex; i++)
				free(tokens[i]);
				free(tokens);
				return (NULL);
		}
		while (letterIndex < tokenLen)
		{
			tokens[tokenIndex][letterIndex] = line[index];
			index++;
			letterIndex++;
		}
		tokens[tokenIndex][letterIndex] = '';
		letterIndex = 0;
		tokenIndex++;
	}
	tokens[tokenIndex] = NULL;
	tokens[tokenIndex + 1] = NULL;
	return (tokens);
}
