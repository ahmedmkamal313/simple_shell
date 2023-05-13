#include "main.h"

/**
 * _strcat - Concatenate two strings.
 * @dest: Pointer to destination string.
 * @src: pinter to source string.
 * Return: pointer to destination string.
 */

char *_strcat(char *dest, char *src)
{
	char *p = dest; /*save the original pointer to dest.*/

	while (*dest) /*move dest to the end of the string.*/
		dest++;

	while (*src) /*copy src to dest.*/
		*dest++ = *src++;

	*dest = '\0'; /*add null terminator */

	return (p); /*return the original pointer to dest. */
}

/**
 * _strcmp - compares two strings.
 * @s1: the 1st string to be compared.
 * @s2: the second string.
 * Return: positing integer if s1 > s2
 * 0 if s1 = s2
 * negative integer if s1 < s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2) /* loop through the characters of the both strings */
	{
		/* if characters are different, return the difference */
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		/* otherwise move to the next characters */
		s1++;
		s2++;
	}

	/* if one string is longer than other, return the difference */
	return (*s1 - *s2);
}
