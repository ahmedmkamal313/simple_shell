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

/**
 * free_alias_list - free a alias lined list.
 * @head: the head of the list.
 */

void free_alias_list(alias_t *head)
{
	alias_t *next; /* a pointer t ostore the next alias */

	while (head) /* loop until the list is empty */
	{
		next = head->next; /* save tje mext alias*/
		free(head->name); /* free the alias name */
		free(head->value); /* free alias value */
		free(head); /* free the current */
		head = next; /* move to the next */
	}
}
