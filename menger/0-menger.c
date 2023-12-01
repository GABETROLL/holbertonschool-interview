#include <math.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * cell_must_be_empty - Given a cell in a menger's sponge
 * (``y``, ``x``), this function returns weather or not that cell should
 * be empty.
 * A cell must be empty, if:
 * while iterating ``N`` through [0, ``level``),
 * both its ``y`` and ``x`` coordinates divided by 3^N
 * are always a multiple of 3.
 *
 * @y: The y coordinate of the cell in the theoretical menger's sponge.
 * It's also the line number for it's print output.
 *
 * @x: The x coordinate of the cell in the theoretical menger's sponge.
 * It's also the char number in the y-th line for it's print output.
 *
 * @level: The level of "recursion" depth of the theoretical menger's
 * sponge.
 *
 * Return: true if the cell must be empty, false if not.
 */
bool cell_must_be_empty(int y, int x, int level)
{
	int div_pow;

	for (div_pow = 0; div_pow < level; div_pow++)
	{
		if
		(
			(x / (int)pow(3, div_pow) - 1) % 3 == 0
			&& (y / (int)pow(3, div_pow) - 1) % 3 == 0
		)
			return (true);
	}
	return (false);
}
/**
 * menger - Prints a menger sponge with level: ``level``.
 * Examples:
 *
 * level 0:
 * #
 * level 1:
 * ###
 * # #
 * ###
 * level 2:
 * #########
 * # ## ## #
 * #########
 * # #   # #
 * #########
 * # ## ## #
 * #########
 * level 3:
 * ###########################
 * # ## ## ## ## ## ## ## ## #
 * ###########################
 * ###   ######   ######   ###
 * # #   # ## #   # ## #   # #
 * ###   ######   ######   ###
 * ###########################
 * # ## ## ## ## ## ## ## ## #
 * ###########################
 * #########         #########
 * # ## ## #         # ## ## #
 * #########         #########
 * ###   ###         ###   ###
 * # #   # #         # #   # #
 * ###   ###         ###   ###
 * #########         #########
 * # ## ## #         # ## ## #
 * #########         #########
 * ###########################
 * # ## ## ## ## ## ## ## ## #
 * ###########################
 * ###   ######   ######   ###
 * # #   # ## #   # ## #   # #
 * ###   ######   ######   ###
 * ###########################
 * # ## ## ## ## ## ## ## ## #
 * ###########################
 * ...
 * @level: Level of depth of "recursion" for the menger sponge.
 * Note that this function uses only iteration.
 * Return: Nothing
 */
void menger(int level)
{
	int size;
	int y;
	int x;

	if (level < 0)
		return;

	size = pow(3, level);
	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			if (cell_must_be_empty(y, x, level))
				putchar(' ');
			else
				putchar('#');
		}
		putchar('\n');
	}
}
