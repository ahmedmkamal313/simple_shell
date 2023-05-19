#include "main.h"

/**
 * free_list - frees a lined list of directories
 * @head: the head of list
 */

void free_list(list_t *head)
{
	list_t *next; /* a pointer to store the next node */

	while (head) /* loop until the list is empty */
	{
		next = head->next; /* save the next node */
		free(head->dir); /* free the directory name */
		free(head); /* free the current node */
		head = next;
	}
}

