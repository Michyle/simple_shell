#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * get_line - This will read a line from standard input
 *
 * Return: A pointer to the line, NULL if an error occurred
 * or end of file is reached
 */
char *get_line(void)
{
	static char buffer[BUFFER_SIZE];
	static size_t position = 0;
	static size_t size =0;

	char *line = NULL;
	size_t len = 0;

	while (1)
       	{
		if (position >= size)
		{
			size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (size == 0)
			{
				return NULL;
			}
			position = 0;
		}
		if (buffer[position] == '\n' || buffer[position] == '\0')
		{
			line = malloc(len +1);
			if (!line)
			{
				perror("malloc");
			}
			exit(EXIT_FAILURE);
		}
		len++;

		position++;
	}
}

