#include "main.h"

/**
 * _realloc - reallocat a memory block using malloc.
 * @ptr: the pointer to the previous memory.
 * @old_size: size of bytes.
 * @new_size: the size of ofg bytes for the new memory block.
 * Return: old_size or NULL otherwise the new memory.
 */

void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;
	size_t min_size;

	/* If new_size is zero and ptr is not NULL, then free ptr and return NULL */
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	/* If ptr is NULL, then allocate new memory of size new_size and return it */
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		return (new_ptr);
	}

	/* If new_size is equal to old_size, then do nothing and return ptr */
	if (new_size == old_size)
	{
		return (ptr);
	}

	/* Allocate new memory of size new_size */
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}

	/* Copy the contents of the old memory block to the new one */
	min_size = (old_size < new_size) ? old_size : new_size;
	memcpy(new_ptr, ptr, min_size);

	/* Free the old memory block */
	free(ptr);

	/* Return the pointer to the new memory block */
	return (new_ptr);
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
	char *buffer; /* Temporary buffer to store input */
	size_t b = 0; /* Size of buffer */
	int c; /* Character read from stream */

	/* If lineptr or n or stream is NULL, return -1 */
	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	/* Allocate memory for buffer */
	buffer = malloc(120 * sizeof(char));
	if (buffer == NULL)
		return (-1);

	/* Flush the output buffer of stream */
	fflush(stream);

	/* Read characters from stream until newline or EOF or error */
	while ((c = read(fileno(stream), &c, 1)) > 0 && c != '\n')
	{
		/* Store character in buffer */
		buffer[b] = c;
		b++;
		/* Reallocate memory for buffer if needed */
		if (b >= 120)
			buffer = realloc(buffer, (b + 1) * sizeof(char));
			if (buffer == NULL)

				return (-1);
	}
	/* Add null terminator to buffer */
	buffer[b] = '\0';
	/* Reassign lineptr and n using assign_lineptr function */
	assign_lineptr(lineptr, n, buffer, b + 1);

	/* If error occurred, return -1 */
	if (c == -1)
		return (-1);

	/* Return number of bytes read */
	return (b + 1);
}
