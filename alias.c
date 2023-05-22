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
