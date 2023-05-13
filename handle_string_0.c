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
