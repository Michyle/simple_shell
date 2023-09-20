#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"
#define MAX_INPUT_SIZE 1024
/**
 *main - Entry point for the shell program.
 *
 *Return: Always 0.
 */

int main()
{
	char input[MAX_INPUT_SIZE];
	ssize_t bytes_read;
	char *token;
	pid_t pid;
	char *args[MAX_INPUT_SIZE];
	int arg_count = 0;

	while (1)
	{
		write(STDOUT_FILENO, "cisfun$ ", 8);

		bytes_read = read_command(input, sizeof(input));
		if (bytes_read == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		else if (bytes_read == 0)
		{
			continue;
		}

		input[strcspn(input, "\n")] = '\0';

		token = strtok(input, " ");
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}

		args[arg_count] = NULL;

		if (arg_count == 0)
		{
			continue;
		}

		if (strcmp(args[0], "exit") == 0)
		{
			exit_builtin();
		}

		pid = fork();

		if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid < 0)
		{
			perror("fork");
		}
		else
		{
			int status;
			waitpid(pid, &status, 0);

			if (WIFEXITED(status))
			{
				printf("Child process exited with status %d\n", WEXITSTATUS(status));
			}
		}
	}

	return 0;


/**
 * @env_variable: gets the enviroment value
 */

int main(int argc, char* argv[])
{
	char* env_variable = getenv("PATH");
	printf("Path = %s\n\n, env_variable");
	return 0;
}
}
