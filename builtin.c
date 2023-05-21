#include "main.h"

/**
 * get_builtin - returns a pointer to a builtin
 * function that matches the given command.
 * @command: The command to match.
 * Return: A function pointer to the corresponding builtin.
 */

int (*get_builtin(char *command))(char **args, char **front)
{
	/*array of structs that store the names and pointers of builtin functions*/
	builtin_t funcs[] = {
		{ "exit", shellby_exit },
		{ "env", shellby_env },
		{ "setenv", shellby_setenv },
		{ "unsetenv", shellby_unsetenv },
		{ "cd", shellby_cd },
		{ "alias", shellby_alias },
		{ "help", shellby_help },
		{ NULL, NULL }
	};
	int i;

	/* Loop through the array and compare the command with each name */
	for (i = 0; funcs[i].name; i++)
	{
		if (_strcmp(funcs[i].name, command) == 0)
			break;
	}
	/* Return the pointer to the matching function or NULL if not found */
	return (funcs[i].f);
}

