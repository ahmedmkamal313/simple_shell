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
 * @s: the pointer to be string.
 * Return: the length.
 */

int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);
	for (length = 0; s[length]; length++)
		;
	return (length);
}

/**
 * _is_included - helper function that checks
 * if a character is in a string.
 * @letter: the character to be check.
 * @prefix: the string to be check.
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

/**
 * _strspn - get the length of a prefix substring.
 * @str: the pointer to be string.
 * @prefix: the string to be check.
 * Return: the length.
 */

unsigned int _strspn(char *str, char *prefix)
{
	unsigned int length = 0; /*Initialize a variable store length “length”.*/

	while (*str != '\0') /*Loop until the end of the string.*/
	{
		if (_is_included(*str, prefix)) /*Check if the current character in prefix.*/
		{
			length++; /*Increment the length by one “ length++’.*/
		}
		else
		{
			break; /*Break the loop if not in prefix.*/
		}
		str++; /*Move the next character “str++”.*/
	}
	return (length); /*Return the length.*/
}

/**
 * _strcpy - copy a string.
 * @dest: the destination.
 * @src: The source of the string.
 * Return: p.
 */

char *_strcpy(char *dest, char *src)
{
	char *p = dest; /*store the original pointer to dest “ char *p = dest ”.*/

	while (*src != '\0') /*Loop until end of string “ *src != ‘\0’ “.*/
	{
		*dest = *src; /*Copy each character from src to dest “ *dest = *src”.*/
		dest++; /*Move to next dest “ dest++”.*/
		src++; /*Move to next src “ src++”.*/
	}
	*dest = '\0'; /*Add null terminator of dest “ *dest = ‘\0’ “.*/

	return (p); /*Return the original pointer to dest “ p “.*/
}
