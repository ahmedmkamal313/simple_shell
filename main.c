#include "main.c"

void clean_up(void)
{
	free_env();
	free_alias_list(aliases);
}

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

	return ret;
}

int handle_non_interactive(int *exe_ret)
{
	int ret = 0;

	while (ret != END_OF_FILE && ret != EXIT)
		ret = handle_args(exe_ret);

	return ret;
}

int main(int argc, char *argv[])
{
	int ret = 0, retn;
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
		ret = proc_file_commands(argv[1], exe_ret);
		clean_up();
		return (*exe_ret);
	}

	if (!isatty(STDIN_FILENO))
	{
		ret = handle_non_interactive(exe_ret);
		clean_up();
		return (*exe_ret);
	}

	ret = handle_interactive(exe_ret);
	clean_up();
	return (*exe_ret);
}
