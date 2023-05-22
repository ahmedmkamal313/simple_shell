#include "main.h"

/**
 * shellby_alias - set or print aliases for commands.
 * @args: pointer to an array of strings containing the alias name and value.
 * @front: a pointer to an unused.
 * Return: the status of the operation. 0 on success
 */

int shellby_alias(char **args, char __attribute__((__unused__)) **front)
{
	alias_t *temp = aliases;
	int i, ret = 0;
	char *value;

	if (!args[0])
	{
		while (temp)
		{
			print_alias(temp); /* print current alias */
			temp = temp->next; /* move to next alias */
		}
		return (ret);
	}
	for (i = 0; args[i]; i++)
	{
		remp = aliases;
		value = _strchr(args[i], '='); /*find equal sign in arg*/
		if (!value)
		{
			while (temp)
			{
				if (_strcmp(args[i], temp->name) == 0)
				{
					print_alias(temp);/* print the matching alias*/
					break;
				}
				temp = temo->next; /*move to the next alias */
			}
			if (!temp)
				ret = create_error(args + i, 1);
		}
		else
			set_alias(args[i], value);
	}
	return (ret);
}

/**
 * set_alias - sets an alias for a variable name with a given value.
 * @var_name: name of the alias.
 * @value: value of the alias.
 */

void set_alias(char *var_name, char *value)
{
	alias_t *temp = aliases; /* pointer to the head of the alias list */
	int len, j, k; /* Variables for string length and loop indices */
	char *new_value; /* pointer to store the new value for the alias */

	*value = '\0'; /* Remove the equal sign from the value string */
	value++; /* Move the pointer to the next character */
	len = _strlen(value) - _strspn(value, "'\"");
	new_value = malloc(sizeof(char) * (len + 1));
	if (!new_value) /*Check if memory allocation failed*/
		return; /* Exit the function */
	for (j = 0, k = 0; value[j]; j++) /* Loop through the value string */
	{
		if (value[j] != '\'' && value[j] != '"')
			new_value[k++] = value[j];
	}
	new_value[k] = '\0'; /*  Add a null terminator to the new value string */
	while (temp) /* Loop through the alias list */
	{
		if (_strcmp(var_name, temp->name) == 0)
		{
			free(temp->value);
			temp->value = new_value;
			break;
		}
		temp = temp->next; /* Move to the next alias in the list */
	}
	if (!temp) /*If no matching alias was found*/
		/*  Add a new alias to the end of the list*/
		add_alias_end(&aliases, var_name, new_value);
}
