#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @old_size: The size in bytes of the allocated space for ptr.
 * @new_size: The size in bytes for the new memory block.
 *
 * Return: If new_size == old_size - ptr.
 *         If new_size == 0 and ptr is not NULL - NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *mem;
	char *ptr_copy, *filler;
	unsigned int index;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		mem = malloc(new_size);
		if (mem == NULL)
			return (NULL);

		return (mem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_copy = ptr;
	mem = malloc(sizeof(*ptr_copy) * new_size);
	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	filler = mem;

	for (index = 0; index < old_size && index < new_size; index++)
		filler[index] = *ptr_copy++;

	free(ptr);
	return (mem);
}

/**
 * _getline - reads input.
 * @lineptr: buffer to store the input.
 * @n: the size.
 * @stream: the stream to read from.
 * Return: the number of bytes.
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char c = 'x', *buffer, *tmp;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * 10); /* allocate a small initial buffer */
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}

		buffer[input] = c;
		input++;

		if (input % 10 == 0) /* if the buffer is full */
		{
			tmp = realloc(buffer, input + 10); /* resize the buffer by 10 more bytes */
			if (!tmp)						   /* if realloc fails */
			{
				free(buffer);
				return (-1);
			}
			buffer = tmp; /* assign the new buffer to the old one */
		}
	}
	buffer[input] = '\0';

	assign_lineptr(lineptr, n, buffer, input);

	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}

/**
 * assign_lineptr - reassign the lineptr variable.
 * @lineptr: buffer to store input.
 * @n: the size.
 * @buffer: the string to be assigned.
 * @b: the size of buffer.
 */

void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		*n = (b > 120) ? b : 120; /* use a ternary operator to assign n */
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		*n = (b > 120) ? b : 120; /* use a ternary operator to assign n */
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer); /* use strcpy() function to copy the buffer */
		if (buffer != NULL) /* check if buffer is NULL before freeing it */
			free(buffer);
	}
}
