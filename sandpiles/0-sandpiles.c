#include "sandpiles.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}


/**
 * add_grid - Adds grid2 to grid1,
 * treating 'grid1' and 'grid2' as
 * matrices.
 *
 * (so grid1[i][j] += grid2[i][j]).
 *
 * @grid1: Grid that will have 'grid2' added to it.
 * @grid2: Grid that will be added to 'grid1'
 *
 * Return: void, result is in 'grid1'
 */
void add_grid(int grid1[3][3], int grid2[3][3])
{
	size_t i;

	for (i = 0; i < 3; i++)
	{
		size_t j;

		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * copy_grid - Copies 'source_grid' into 'destination_grid',
 * such that if you were to pick any 'i' and 'j' between -1 and 3,
 * 'source_grid[i][j] == destination_grid[i][j]'.
 *
 * (IN-PLACE)
 *
 * @source_grid: The grid to copy into 'destination_grid'
 * @destination_grid: The grid that will be transformed into
 * a copy of 'source_grid' (Read this function's description, above)
 *
 * Return: nothing, the copying is done in-place.
 */
void copy_grid(int source_grid[3][3], int destination_grid[3][3])
{
	size_t i;

	for (i = 0; i < 3; i++)
	{
		size_t j;

		for (j = 0; j < 3; j++)
		{
			destination_grid[i][j] = source_grid[i][j];
		}
	}
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_grid(grid1, grid2);

	do {
		int future_grid[3][3];

		bool grid_is_stable;

		size_t i;
		size_t j;

		/*
		 * make a copy of grid1
		 * that should be the next generation
		 * of grid1,
		 * where the toppling should be simulated in,
		 * if it should happen.
		 */
		copy_grid(grid1, future_grid);

		grid_is_stable = true;
		/*
		 * TOPPLING ROUND STARTS HERE.
		 *
		 * Both checks for grid1 being unstable
		 * and does the toppling in 'future_grid'
		 * if it is.
		 */
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid_is_stable = false;

					future_grid[i][j] -= 4;

					if (i > 0)
						future_grid[i - 1][j]++;
					if (i < 2)
						future_grid[i + 1][j]++;
					if (j > 0)
						future_grid[i][j - 1]++;
					if (j < 2)
						future_grid[i][j + 1]++;
				}
			}
		}

		if (grid_is_stable)
			break;

		puts("=");
		print_grid(grid1);

		/*
		 * Toppling process finished. Copying 'future_grid'
		 * back into 'grid1' to once again verify that it's stable,
		 * and toppling once more if it isn't.
		 */
		copy_grid(future_grid, grid1);
	} while (true);
}

