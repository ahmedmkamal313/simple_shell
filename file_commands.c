#include "main.h"

/**
 * read_file - reads the content of a file and stores it in a buffer
 * @file_path: the path of the file to read
 * @line: a pointer to the buffer where the content will be stored
 * @exe_ret: pointer to an integer that stores the return value of the function
 * Return: the size of the buffer in bytes, or -1 on failure.
 */

int read_file(char *file_path, char **line, int *exe_ret)
{
	ssize_t file, b_read;
	unsigned int line_size = 0;
	unsigned int old_size = 120;
	char buffer[120];

	file = open(file_path, O_RDONLY);
	if (file == -1)
		return (*exe_ret = cant_open(file_path));
	*line = malloc(sizeof(char) * old_size);
	if (!*line)
		return (-1);
	do {
		b_read = read(file, buffer, 119);
		if (b_read == 0 && line_size == 0)
			return (*exe_ret);
		buffer[b_read] = '\0';
		line_size += b_read;
		*line = _realloc(*line, old_size, line_size);
		_strcat(*line, buffer);
		old_size = line_size;
		} while (b_read);
	return (line_size);
}

/**
 * proc_file_commands - Takes a file and attempts to run the commands stored.
 * @file_path: Path to the file.
 * @exe_ret: Return value of the last executed command.
 * Return: return value
 */

int proc_file_commands(char *file_path, int *exe_ret)
{
	char *line, **args, **front;
	int line_size, ret;

	history = 0;
	line_size = read_file(file_path, &line, exe_ret);
	if (line_size == -1)
		return (-1);
	for (int i = 0; line[i] == '\n'; i++)
		line[i] = ' ';
	for (int i = 0; i < line_size; i++)
		line[i] = (line[i] == '\n') ? ';' : line[i];
	variable_replacement(&line, exe_ret);
	handle_line(&line, line_size);
	args = _strtok(line, " ");
	free(line);
	if (!args || check_args(args) != 0)
		return (*exe_ret = 2);
	front = args;
	for (int i = 0; args[i]; i++)
	{
		if (_strncmp(args[i], ";", 1) == 0)
		{
			free(args[i]);
			args[i] = NULL;
			ret = call_args(args, front, exe_ret);
			args = &args[++i];
			i = 0;
		}
	}
	ret = call_args(args, front, exe_ret);
	free(front);
	return (ret);
}
