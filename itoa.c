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

		num1 = num * -1 /* make num1 positive.*/
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
