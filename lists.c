#include "main.h"

/**
 * add_node_end - adds a new node at the end of a linked list of directories
 * @head: the head of the list
 * @dir: path for the new node
 * Return: new node , null if error
 */

list_t *add_node_end(list_t **head, char *dir)
{
	list_t *last; /*pointer to store the last node */
	/* allocate memory fr the new node */
	list_t *new_node = malloc(sizeof(list_t));

	if (!new_node) /* check f meory allocation failed */
		return (NULL);
	new_node->dir = dir; /* assign dir name to new node */
	new_node->next = NULL; /* set next pointer of new node to null*/
	if (*head) /** check if the list is not empty */
	{
		last = *head;
		while (last->next != NULL) /* loop until the last node*/
			last = last->next; /* move to next node */
		last->next = new_node; /* link last node to new node */
	}
	else
		/* if the list is empty, set the head to new node */
		*head = new_node;
	return (new_node); /* return the new node */
}

/**
 * add_alias_end - adds a new alias at the end of a linked list of aliases
 * @head: pointer to the head of the list
 * @name: ame of the new alias to add
 * @value: value of the new alias
 * Return: the new node, NULL if fail
 */

alias_t *add_alias_end(alias_t **head, char *name, char *value)
{
	/* Allocate memory for the new alias */
	alias_t *new_node = malloc(sizeof(alias_t));
	alias_t *last; /* pointer to store the last alisas */

	if (!new_node) /* Check if memory allocation failed */
		return (NULL);
	new_node->next = NULL; /* set the next to NULL */
	/* Allocate memory for the alias name */
	new_node->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (!new_node->name) /* Check if memory allocation failed */
	{
		free(new_node); /* free te nea alias */
		return (NULL);
	}
	new_node->value = value; /* Assign the alias value to the new alias */
	_strcpy(new_node->name, name); /*Copy the alias name to the new alias */
	if (*head) /* check if the list is not empty */
	{
		last = *head; /* Initialize the last pointer to the head of the list*/
		while (last->next != NULL) /*Loop until the last alias is found */
			last = last->next; /*Move the last pointer to the next alias */
		last->next = new_node; /* Link the last alias to the new alias */
	}
	else
		*head = new_node;
	return (new_node);
}
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
	alias_t *next;/* a pointer t ostore the next alias */

	if (head == NULL)/* check if head is NULL */
		return;/* do nothing if head is NULL */
	while (head)/* loop until the list is empty */
	{
		next = head->next;/* save tje mext alias*/
		free(head->name);/* free the alias name */
		free(head->value);/* free alias value */
		free(head);/* free the current */
		head = next;/* move to the next */
	}
}
