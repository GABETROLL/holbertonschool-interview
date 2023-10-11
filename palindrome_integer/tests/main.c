#include <stdlib.h>
#include <stdio.h>

#include "../palindrome.h"

/**
 * main - Entry point:
 * Using ONLY ONE shell argument,
 * this program uses the 'is_palindrome'
 * function defined in the header file
 * to tell the user if the argument is
 * a palindrome.
 *
 * If there's not EXACTLY one command line
 * argument after the executable's name,
 * this function corrects the user and exits
 * with code 'EXIT_FAILURE'.
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
	unsigned long n;
	int ret;

	if (ac < 2)
	{
		fprintf(stderr, "Usage: %s arg\n", av[0]);
		return (EXIT_FAILURE);
	}

	n = (unsigned long)(atol(av[1]));
	ret = is_palindrome(n);

	printf("%lu is ", n);
	if (ret == 0)
		printf("not ");
	printf("a palindrome.\n");

	return (EXIT_SUCCESS);
}

