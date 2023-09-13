#include <stdlib.h>
#include <stdio.h>

#include "../sandpiles.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	int grid1[3][3] = {
		{3, 3, 3},
		{3, 3, 3},
        {3, 3, 3}
    };
	int grid2[3][3] = {
        {1, 3, 1},
        {3, 3, 3},
        {1, 3, 1}
    };

    print_grid_sum(grid1, grid2);

    sandpiles_sum(grid1, grid2);

    printf("=\n");
    print_grid(grid1);

    return (EXIT_SUCCESS);
}

