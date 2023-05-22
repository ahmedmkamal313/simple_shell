#include "main.h"

/**
 * num_len - Counts the digit length of a number.
 * @num: the number to be count.
 * Return: length.
 */

int num_len(int num)
{
	unsigned int num1; /*Variable to store the absolute value of num (num1).*/
	int length = 1; /*Variable to store the length, initialized to 1 (length).*/

	/*If the number is negative, increment the length and make num1 positive.*/
	if (num < 0)
	{
		length++; /*Otherwise, assign num to num1.*/

		num1 = num * -1; /* make num1 positive.*/
	}
	else
	{
		num1 = num;
	}

	while (num > 9)
	{
		length++;
		num1 /= 10;
	}

	return (length); /*Return the length.*/
}

/**
 * _itoa - Converts an int to a string.
 * @num: the number to be count.
 * Return: beffer.
 */

char *_itoa(int num)
{
	/*Variable to store the length of the string (length = num_len(num).*/
	int length = num_len(num);
	/*Variable to store the absolute value of num (num1).*/
	unsigned int num1;
	/*Variable to store the string (buffer).*/
	char *buffer;

	/*Allocate memory for the string, including the null terminator.*/
	buffer = malloc(sizeof(char) * (length + 1));

	if (!buffer) /*Check if memory allocation was successful.*/
		return (NULL);

	buffer[length] = '\0'; /*Set the last character of the string to '\0'.*/

	/*If number is negative, set first character to '-' and make num1 positive.*/
	if (num < 0)
	{
		num1 = num * -1;
		buffer[0] = '-';
	}
	else /*Otherwise, assign num to num1.*/
	{
		num1 = num;
	}
	/*Loop from end of string to second character (or first if positive).*/

	length--;

	do {
		/*Set the current character to the last digit of num1 plus '0'.*/
		buffer[length] = (num1 % 10) + '0';
		num1 /= 10; /*Divide num1 by 10 to remove the last digit.*/
		length--; /*Decrement len to move to the previous character.*/
	} while (num1 > 0);

	return (buffer);
}
