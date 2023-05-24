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
	const char *source = src;

	while (*p != '\0') /*move dest to the end of the string.*/
		p++;

	while (*source != '\0') /*copy src to dest.*/
		*p++ = *source++;

	*p = '\0'; /*add null terminator */

	return (dest); /*return the original pointer to dest. */
}

/**
 * _strncat - concatenates two string by copying n bytes from the source.
 * @dest: the destination string.
 * @src: the source string.
 * @n: the number of bytes to copy from the source.
 * Return: a pointer to the destination string.
 */

char *_strncat(char *dest, const char *src, size_t n)
{
	/* declare a variable to store the length of the destination string */
	size_t dest_len = _strlen(dest);
	/* declare a variable to loop through the source string */
	size_t i;

	/* loop through the source string until n is reached or null */
	for (i = 0; i < n && src[i] != '\0'; i++)
		/* copy the char from the source to end of dest */
		dest[dest_len + i] = '\0';
	/* return pointer to destination string */
	return (dest);
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

/**
 * _strncmp - Compares two strings up to n characters.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 * @n: The number of characters to compare.
 * Return: Positive integer if s1 > s2
 * 0 if s1 = s2
 * Negative integer if s1 < s2
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	/* loop through character of both strings until n or null */
	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		/* if the characters are ifferent return the difference */
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	/* if n is reached, return 0 */
	if (i == n)
		return (0);
	/* otherwise, return -15 */
	else
		return (-15);
}
