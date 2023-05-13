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

/**
 * _strlen - return the length of a string.
 * @str: the pointer to be string.
 * Return: the length.
 */

int _strlen(char *str)
{
	int len = 0; /*Initialize a variable to store length “ len = 0 “.*/

	while (*str != '\0') /*Loop until the end of the string.*/
	{
		len++; /*ncrement the length by one “ len ++”.*/
		str++; /*Move to the next character “ str ++”.*/
	}
	return (length); /*Return the length.*/
}

/**
 * _is_included - helper function that checks
 * if a character is in a string.
 * @letter: the character to be check.
 * @*prefix: the string to be cheack.
 * Return: 0.
 */

int _is_included(char letter, char *prefix)
{
	while (*prefix != '\0') /*Loop through prefix.*/
	{
		if (*prefix == letter) /*Check if letter matches any character in prefix.*/
		{
			return (1); /*Return 1 if found.*/
		}
		prefix++; /*Move to next character “ prefix++ “.*/
	}
	return (0); /*Return 0.*/
}
