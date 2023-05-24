#include "main.h"

/**
 * get_args - gets the arguments from the standard input
 * and performs some operations on them.
 * @line: the string buffer to start the command.
 * @exe_ret: the value of executed command.
 * Return: NULL if error, or line.
 */

char *get_args(char *line, int *exe_ret)
{
	size_t n = 0; /*the size of the buffer for getline (size_t ……..)*/
	ssize_t read; /*the number of bytes read by getline (ssize_t …….. )*/
	char *prompt = "$ "; /*The prompt to display ( char *prompt - “$ “.*/

	if (line != NULL) /*if the line is not NULL free it.*/
		free(line);

	/*read a line from standard input (read = _getlne(&line, &n, STDIN_FILENO)*/
	read = _getline(&line, &n, STDIN_FILENO);
	if (read == -1 || read == 0) /*if there is an error or EOF return null.*/
		return (NULL);

	if (read == 1) /*if line is empty ( read == 1).*/
	{
		history++;
		if (isatty(STDIN_FILENO)) /*f (isatty(STDIN_FILENO)).*/
			write(STDOUT_FILENO, prompt, 2);
		return (get_args(line, exe_ret));
	}
	/*Replace the newline character with a null terminator.*/
	line[read - 1] = '\0';
	/*Replace any variables in the line with their >>.*/
	variable_replacement(&line, exe_ret);
	/*Handle any special characters or commands in the line.*/
	handle_line(&line, read);
	return (line); /*Return the modified line.*/
}

/**
 * call_args - partition operators from commands and calls them.
 * @front: the beginning of the array.
 * @exe_ret: the value of executed command.
 * @args: the argument of array
 * Return: the return value.
 */

int call_args(char **args, char **front, int *exe_ret)
{
	int ret, index;

	if (!args[0])
		return (*exe_ret);
	for (index = 0; args[index]; index++)
	{
		if (_strncmp(args[index], "||", 2) == 0)
			ret = handle_operators(args, front, exe_ret, "||");
		else if (_strncmp(args[index], "&&", 2) == 0)
			ret = handle_operators(args, front, exe_ret, "&&");
	}
	args = replace_aliases(args);
	ret = run_args(args, front, exe_ret);
	return (ret);
}

/**
 * handle_operators - handles the logical operators || and && in the arguments.
 * @args: the array of arguments.
 * @front: the pointer to the first argument.
 * @exe_ret: the pointer to the execution return value.
 * @op: a string representing the operator ("||" or "&&")
 * Return: 0 or the return value of run_args
 * if an operator is found, -1 otherwise.
 */

int handle_operators(char **args, char **front, int *exe_ret, char *op)
{
	int ret;
	int index = 0;

	free(args[index]);
	args[index] = NULL;
	args = replace_aliases(args);
	ret = run_args(args, front, exe_ret);
	if (*exe_ret == (_strncmp(op, "||", 2) == 0 ? 0 : 1))
	{
		for (index++; args[index]; index++)
			free(args[index]);
		return (ret);
	}
	else
	{
		args = &args[++index];
		index = 0;
	}
	return (0);
}
