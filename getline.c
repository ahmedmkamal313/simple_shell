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
