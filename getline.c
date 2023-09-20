#include <stdio.h>
#include <unistd.h>

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
			else
				if (size < 0)
				{
					perror("read");
					exit(EXIT_FAILURE);
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
		len++

		position++
	}
}

int main(void)
{
	char *line;

	while (1) 
	{
		print("$ ");
		line = get_line();
		if (line == NULL)
		{
			printf("\n");
			break
		}
		printf("You entered: %s\n", line);
		free(line);
	}

	return 0;
}
