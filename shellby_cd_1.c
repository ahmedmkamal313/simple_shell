#include "main.h"

/**
 * chdir_to_home - changes the current working directory to the home directory.
 * Return: nothing.
 */

void chdir_to_home(void)
{
	if (_getenv("HOME") != NULL)
		chdir(*(_getenv("HOME")) + 5);
}

/**
 * update_env - updates the environment variables OLDPWD and PWD.
 * @oldpwd: the previous working directory.
 * @pwd: the current working directory.
 * Return: 0 on success, -1 on failure.
 */

int update_env(char *oldpwd, char *pwd)
{
	char **dir_info;

	dir_info = malloc(sizeof(char *) * 2);
	if (!dir_info)
		return (-1);

	dir_info[0] = "OLDPWD";
	dir_info[1] = oldpwd;
	if (shellby_setenv(dir_info, dir_info) == -1)
		return (-1);

	dir_info[0] = "PWD";
	dir_info[1] = pwd;
	if (shellby_setenv(dir_info, dir_info) == -1)
		return (-1);

	free(dir_info);
	return (0);
}
