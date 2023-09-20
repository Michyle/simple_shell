#include "shell.h"

/**
 * _exec - A function that executes a command.
 * @command: The pointer to tokienized command
 * @name: The name of the shell.
 * @env: The pointer to the enviromental variables.
 * @nec: Number of executed cicles.
 * Return: Nothing.
 */
void _exec(char **command, char *name, char **env, int nec)
{
	char **pathways = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (compare_strings(command[0], "env") != 0)
		print_env(env);
	if (stat(command[0], &st) == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(name);
			exit_free(command);
		}
	}
	else
	{
		pathways = _getPATH(env);
		while (pathways[i])
		{
			full_path = concatenate_strings(pathways[i], command[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, command, env) < 0)
				{
					perror(name);
					_pd(pathways);
					exit_free(command);
				}
				return;
			}
		}
		msgerror(name, nec, command);
		_pd(pathways);
	}
}


/**
 * print_env - A function that prints all enviromental variables.
 * @env: The pointer to enviromental variables.
 * Return: Nothing.
 */
void print_env(char **env)
{
	size_t i = 0, len = 0;

	while (env[i])
	{
		len = string_length(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}


/**
 * _getPATH - A function to gets the full value from.
 * enviromental variable PATH.
 * @env: The pointer to enviromental variables.
 * Return: All tokenized pathways for commands.
 */
char **_getPATH(char **env)
{
	char *pathvalue = NULL, **pathways = NULL;
	unsigned int i = 0;

	pathvalue = strtok(env[i], "=");
	while (env[i])
	{
		if (compare_strings(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, "\n");
			pathways = tokenizing(pathvalue, ":");
			return (pathways);
		}
		i++;
		pathvalue = strtok(env[i], "=");
	}
	return (NULL);
}


/**
 * msgerror - A function that prints message not found.
 * @name: The name of the shell.
 * @nec: Number of cicles.
 * @command: The pointer to tokenized command.
 * Return: Nothing.
 */
void msgerror(char *name, int nec, char **command)
{
	char c;

	c = nec + '0';
	write(STDOUT_FILENO, name, string_length(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], string_length(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}

