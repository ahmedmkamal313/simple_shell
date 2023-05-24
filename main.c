#include "main.h"

/* Define the global variables here */
alias_t *aliases; /* define the variable here */
char *name; /* define the variable here */
int hist; /* define the variable here */

/**
 * clean_up - cleans up the memory allocated for
 * the environment variables and the alias list
 * Return: nothing
 *
 * Description: This function calls free_env and free_alias_list
 */

void clean_up(void)
{
	free_env();
	free_alias_list(aliases);
}

/**
 * handle_interactive - handles the interactive mode of the shell
 * @exe_ret: a pointer to an int that stores the execution return value
 * Return: the return value
 *
 * Description: This function loops until the end of file
 * or exit and writes a prompt and calls handle_args
 */

int handle_interactive(int *exe_ret)
{
	int ret = 0;
	char *prompt = "$ ", *new_line = "\n";

	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		ret = handle_args(exe_ret);
		if (ret == END_OF_FILE || ret == EXIT)
		{
			if (ret == END_OF_FILE)
				write(STDOUT_FILENO, new_line, 1);
			break;
		}
	}

	return (ret);
}

/**
 * handle_non_interactive - handles the non-interactive mode of the shell
 * @exe_ret: a pointer to an int that stores the execution return value
 * Return: the return value
 *
 * Description: This function loops until
 * the end of file or exit and calls handle_args
 */

int handle_non_interactive(int *exe_ret)
{
	int ret = 0;

	while (ret != END_OF_FILE && ret != EXIT)
		ret = handle_args(exe_ret);

	return (ret);
}

/**
 * main - the main function of a shell program
 * @argc: the number of arguments
 * @argv: the array of arguments
 * Return: the execution return value
 *
 * Description: This function initializes some global variables,
 * registers a signal handler,
 * copies the environment variables,
 * and handles different modes of input
 */

int main(int argc, char *argv[])
{
	int retn;
	int *exe_ret = &retn;

	program_name = argv[0];
	history = 1;
	aliases = NULL;
	signal(SIGINT, sig_handler);

	*exe_ret = 0;
	environ = _copyenv();
	if (!environ)
		exit(-100);

	if (argc != 1)
	{
		proc_file_commands(argv[1], exe_ret);
		clean_up();
		return (*exe_ret);
	}

	if (!isatty(STDIN_FILENO))
	{
		handle_non_interactive(exe_ret);
		clean_up();
		return (*exe_ret);
	}

	handle_interactive(exe_ret);
	clean_up();
	return (*exe_ret);
}
