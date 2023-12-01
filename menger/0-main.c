#include <stdio.h>
#include <stdlib.h>

#include "menger.h"

/**
 * main - Takes in one shell argument,
 * uses ``atoi`` to convert it to an int,
 * then calls ``menger`` from ``menger.h``
 * with it.
 *
 * If the int argument is wrong, ``atoi`` will just
 * return a 0, and the menger sponge output
 * will be a level 0.
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
	int level;

	if (ac < 2)
	{
		fprintf(stderr, "Usage: %s level\n", av[0]);
		return (EXIT_FAILURE);
	}

	level = atoi(av[1]);
	menger(level);

	return (EXIT_SUCCESS);
}
