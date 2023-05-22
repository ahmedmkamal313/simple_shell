#include "main.h"

/**
 * shellby_cd - Changes the current directory of the shellby process.
 * @args: an array of arguments.
 * @front: a double pointer to the beginning of args.
 * Return: If the given string is not a directory - 2.
 * If an error occurs - -1.
 */

int shellby_cd(char **args, char __attribute__((__unused__)) **front)
{
	char *oldpwd = NULL, *pwd = NULL;
	struct stat dir;

	oldpwd = getcwd(oldpwd, 0);
	if (!oldpwd)
		return (-1);

	if (args[0])
	{
		if (is_dash(args[0]))
			chdir_to_oldpwd();
		else if (is_valid_dir(args[0], &dir))
			chdir(args[0]);
		else
			return (handle_error(args, oldpwd));
	}
	else
		chdir_to_home();

	pwd = getcwd(pwd, 0);
	if (!pwd)
		return (-1);

	if (update_env(oldpwd, pwd) == -1)
		return (-1);

	if (args[0] && is_dash(args[0]))
		print_pwd(pwd);

	free(oldpwd);
	free(pwd);
	return (0);
}

/**
 * is_dash - checks if a string is a dash or a double dash.
 * @arg: the string to check.
 * Return: 1 if arg is "-" or "--", 0 otherwise.
 */

int is_dash(char *arg)
{
	return ((*(arg) == '-' || _strcmp(arg, "--") == 0) &&
		((arg[1] == '-' && arg[2] == '\0') || arg[1] == '\0'));
}

/**
 * chdir_to_oldpwd - change the current wokring directory to the previous one.
 * Return: nothing.
 */

void chdir_to_oldpwd(void)
{
	if (_getenv("OLDPWD") != NULL)
		chdir(*_getenv("OLDPWD") + 7);
}

/**
 * is_valid_dir - check if a string is valid directory.
 * @arg: the string to check
 * @dir: a pointer to a stract stat to store the file information.
 * Return: 1 if arg is a valid directory, 0 otherwise.
 */

int is_valid_dir(char *arg, struct stat *dir)
{
	return (stat(arg, dir) == 0 && S_ISDIR(dir->st_mode) &&
			((dir->st_mode & S_IXUSR) != 0));
}

/**
 * handle_error - handles an error by freeing oldpwd and calling create_error.
 * @args: the array og arguments.
 * @oldpwd: the previous working a directory.
 * Return: the value returned by create_error.
 */

int handle_error(char **args, char *oldpwd)
{
	free(oldpwd);
	return (create_error(args, 2));
}
