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