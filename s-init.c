#include "shell.h"

/**
 * main - A function that runs our shell.
 * @ac: The number of inputed arguments.
 * @av: The pointer to array of inputed arguments.
 * @env: The pointer to array of enviromental variables.
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL, **command = NULL;
	size_t buf_size = 0;
	ssize_t num_chars_red = 0;
	int circles = 0;
	(void)ac;

	while (1)
	{
		circles++;
		prompt();
		signal(SIGINT, handle);
		num_chars_red = getline(&buffer, &buf_size, stdin);
		if (num_chars_red == EOF)
			end_of_file(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[string_length(buffer) - 1] = '\0';
			command = tokenizing(buffer, " \0");
			free(buffer);
			if (compare_strings(command[0], "exit") != 0)
				shell_exit(command);
			else if (compare_strings(command[0], "cd") != 0)
				ch_pwd(command[1]);
			else
				child_process(command, av[0], env, circles);
		}
		fflush(stdin);
		buffer = NULL, buf_size = 0;
	}
	if (num_chars_red == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


/**
 * prompt - A function that prints the prompt
 * Return: Nothing.
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$", 13);
}


/**
 * handle - A function to handle Ctr + C signal.
 * @signals: The signal to handle.
 * Return: Nothing.
 */
void handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\n$", 14);
}


/**
 * end_of_file - A function that checks if buffer is EOF
 * @buffer: The pointer to the input string.
 * Return: Nothing
 */
void end_of_file(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}


/**
 * shell_exit - A function that exits the shell.
 * @command: The pointer to tokenized command.
 * Return: Nothing.
 */
void shell_exit(char **command)
{
	int sttus = 0;

	if (command[1] == NULL)
	{
		_pd(command);
		exit(EXIT_SUCCESS);
	}

	sttus = string_to_int(command[1]);
	_pd(command);
	exit(sttus);
}

