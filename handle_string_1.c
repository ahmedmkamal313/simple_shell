#include "main.h"

/**
 * _strchr - locate a character in a string.
 * @str: the string to be check.
 * @ch: the character to be located.
 * Return: NULL if ch isn’t found.
 */

char *_strchr(char *str, char ch)
{
	while (*str != '\0') /*Loop until the end of the string.*/
	{
		if (*str == ch) /*Check if current character “str” matches “ch”.*/
			return (str); /*Return a pointer to the first >> “str.*/
	}
	str++; /*move to the next character “str++”.*/
	return (NULL); /*return null if ch isn’t found.*/
}
