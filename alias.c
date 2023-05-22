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
		temp = aliases;
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
				temp = temp->next; /*move to the next alias */
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

/**
 * print_alias -  prints an alias in the format name='value'\n
 * @alias: a pointer to an alias_t struct
 */

void print_alias(alias_t *alias)
{
	char *alias_string; /* A pointer to store the formatted alias string */
	int len =  _strlen(alias->name) + _strlen(alias->value) + 4;

	alias_string = malloc(sizeof(char) * (len + 1));
	if (!alias_string) /* Check if memory allocation faild */
		return; /* exit */
	/*Copy the name of the alias to the alias string*/
	_strcpy(alias_string, alias->name);
	/*Append an equal sign and a single quote to the alias string*/
	_strcat(alias_string, "='");
	/*Append the value of the alias to the alias string*/
	_strcat(alias_string, alias->value);
	/*Append a single quote and a newline to the alias string*/
	_strcat(alias_string, "'\n");

	/* Write the alias string to the standard output*/
	write(STDOUT_FILENO, alias_string, len);
	free(alias_string); /*Free the memory allocated for the alias string*/
}

/**
 * replace_aliases - replaces any aliases in the given arguments
 * array with their corresponding values
 * @args: array of arguments.
 * Return: pointer to arguments.
 */

char **replace_aliases(char **args)
{
	alias_t *temp; /* A pointer to traverse the aliases list*/
	int i; /* loop variable counter */
	char *new_value; /* A pointer to store the new value of an alias */

	/*If 1st argument is "alias", dont replace and return arguments as they are*/
	if (_strcmp(args[0], "alias") == 0)
		return (args);
	for (i = 0; args[i]; i++)/*Loop through each argument in the array*/
	{
		temp = aliases; /*Set temp to point to the head of the aliases list*/
		while (temp) /* Loop through each alias in the list*/
		{
			if (_strcmp(args[i], temp->name) == 0)
			{
				new_value = malloc(sizeof(char) * (_strlen(temp->value) + 1));
				if (!new_value)
				{
					free_args(args, args);
					return (NULL);
				}
				_strcpy(new_value, temp->value);
				free(args[i]);
				args[i] = new_value;
				i--;
				break;
			}
			temp = temp->next;
		}
	}
	return (args);
}
