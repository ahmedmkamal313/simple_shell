#include "main.h"

/**
 * sig_handler - handles the SIGINT signal by printing a new prompt
 * @sig: the signal number
 * Return: nothing
 */

void sig_handler(int sig)
{
	char *new_prompt = "\n$ ";

	(void)sig; /* to avoid unused variable warning */

	signal(SIGINT, sig_handler); /*This is to reset the signal handler */
	write(STDIN_FILENO, new_prompt, 3); /*this is to print a new prompt */
}

/**
 * execute - Executes a command in a child process.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 * Return: If an error occurs - a corresponding error code.
 * O/w - The exit value of the last executed command.
 */

int execute(char **args, char **front)
{
	char *command = args[0];
	int flag = 0, ret = 0;

	if (command[0] != '/' && command[0] != '.')
	{
		flag = 1;
		command = get_location(command);
	}

	if (!command || (access(command, F_OK) == -1))
	{
		if (errno == EACCES)
			ret = (create_error(args, 126));
		else
			ret = (create_error(args, 127));
	}
	else
	{
		ret = execute_command(command, args, front);
	}

	if (flag)
		free(command);
	return (ret);
}

/**
 * execute_command - executes a given command with the
 * given arguments and environment variables
 * @command: the command to execute
 * @args: the array of arguments
 * @front: a pointer to the first element of args
 * Return: the exit status of the command
 */

int execute_command(char *command, char **args, char **front)
{
	pid_t child_pid;
	int status, ret = 0;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error child:");
		return (1);
	}
	if (child_pid == 0)
	{
		execve(command, args, environ);
		if (errno == EACCES)
			ret = (create_error(args, 126));
		free_env();
		free_args(args, front);
		free_alias_list(aliases);
		_exit(ret);
	}
	else
	{
		wait(&status);
		ret = WEXITSTATUS(status);
	}
	return (ret);
}
