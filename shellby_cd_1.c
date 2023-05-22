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
