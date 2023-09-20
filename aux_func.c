#include "shell.h"

/**
 * compare_strings - A funtion that compares two strings
 * @strng1: string 1
 * @strng2: string 2
 * Return: 1 if strings are the same, 0 if not
 */
int compare_strings(char *strng1, char *strng2)
{
	unsigned int i = 0;

	while (strng1[i])
	{
		if (strng1[i] != strng2[i])
			return (0);
		i++;
	}

	return (1);
}


/**
 * string_length - A function that finds the length of the string
 * @s: The input string
 * Return: The length of the string
 */
unsigned int string_length(char *strng)
{
	unsigned int len = 0;

	while (strng[len])
		len++;

	return (len);
}


/**
 * copy_string - A function that copies a string to another string
 * @destination: The pointer to the copyed string
 * @source: The pointer to string to copy for
 * Return: A pointer to copied string
 */
char *copy_string(char *destination, char *source)
{
	char *aux = destination;

	while (*source)
		*destination++ = *source++;
	*destination = '\0';
	return (aux);
}


/**
 * concatenate_strings - a function that concatenates two strings.
 * @destination: an input string
 * @source: an input string
 * Return: A pointer to the resulting string
 */
char *concatenate_strings(char *destination, char *source)
{
	char *temp = destination;

	while (*destination)
		destination++;

	*destination++ = '/';
	while (*source)
		*destination++ = *source++;
	return (temp);
}


/**
 * string_to_int - a function that converts string to integer.
 * @s: An input string.
 * Return: integer from conversion.
 */
int string_to_int(char *strng)
{
	int si = 1;
	unsigned int totl = 0;
	char nilflags = 0;

	if (strng == NULL)
		return (0);
	while (*strng)
	{
		if (*strng == '-')
			si *= -1;
		if (*strng >= '0' && *strng <= '9')
		{
			nilflags = 1;
			totl = totl * 10 + (*strng - '0');
		}
		else if (*strng < '0' || *strng > '9')
		{
			if (nilflags == 1)
				break;
		}
		strng++;
	}
	if (si < 0)
		totl = (-1 * (totl));
	return (totl);
}

