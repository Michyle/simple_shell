#include "shell.h"

/**
 * tokenizing - A function that split and create a full string command.
 * @s: The delimiter for strtok.
 * @buffer: The pointer to input string.
 * Return: A string with full command.
 */
char **tokenizing(char *buffer, const char *s)
{
	char *token = NULL, **commands = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	bufsize = string_length(buffer);
	commands = malloc((bufsize + 1) * sizeof(char *));
	if (commands == NULL)
	{
		perror("Unable to allocate buffer");
		free(buffer);
		_pd(commands);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, s);
	while (token != NULL)
	{
		commands[i] = malloc(string_length(token) + 1);
		if (commands[i] == NULL)
		{
			perror("Unable to allocate buffer");
			_pd(commands);
			return (NULL);
		}
		copy_string(commands[i], token);
		token = strtok(NULL, s);
		i++;
	}
	commands[i] = NULL;
	return (commands);
}

