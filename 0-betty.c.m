#include <stdio.h>

/**
 * fibonacci - This will generate the sequence up to n
 *
 * @n: The number of Fibonacci numbers to generate
 *
 * Return: none
 */
void fibonacci(int n)
{
	int i, first = 0, second = 1 , next;

	for (i = 0; i < n; i++)
	{
		if (i <=1)
			next =i;
		else
		{
			  next = first + second;
			  first = second;
			  second = next;
		}
		printf("%d", next);
		if (i < n - 1)
			 printf(", ");
	}
	printf("\n");
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	fibonacci(10);
       	return (0);
}
