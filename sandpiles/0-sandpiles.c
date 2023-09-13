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
		 * of grid1
		 */
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				future_grid[i][j] = grid1[i][j];
			}
		}

		grid_is_stable = true;
		/*
		 * CREATING NEXT GENERATION OF 'grid1':
		 *
		 * Subtract 4 from the cells that have more than 3 sandpiles,
		 * and those sandpiles to its neighbors
		 * up, down, left and right; if the grid were
		 * a physical floor with sandpiles on it.
		 *
		 * BUT only if those neighbors are inside the grid.
		 *
		 * IF ANY CELL WERE TO HAVE > 3 SANDPILES IN IT,
		 * 'grid1' IS STILL UNSTABLE, AND 'grid_is_stable'
		 * SHOULD BE CHANGED TO 'false'.
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

		/*
		 * If there are no more cells with > 3 sandpiles,
		 * We have finally stabilized the grid,
		 * and we can break the loop!
		 */

		if (grid_is_stable)
			break;

		puts("=");
		print_grid(grid1);

		/*
		 * Copy 'future_generation' back into 'grid1' to begin
		 * the next toppling iteration,
		 * since this one had cells with > 3 sandpiles,
		 * we still need this next iteration to check that
		 * the grid is stable then.
		 */
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] = future_grid[i][j];
			}
		}

	} while (true);
}

