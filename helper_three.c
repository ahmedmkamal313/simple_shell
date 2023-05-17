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
	read = getline(&line, &n, STDIN_FILENO);
	if (read == -1 || read == 0) /*if there is an error or EOF return null.*/
		return (NULL);

	if (read == 1) /*if line is empty ( read == 1).*/
	{
		(*exe_ret)++;
		if (isatty(STDIN_FILEDO)) /*f (isatty(STDIN_FILENO)).*/
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
