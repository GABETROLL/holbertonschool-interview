#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - TRIES TO:
 * create new binary_tree_t type node in memory,
 * with: 'value' as its 'n' int attribute, 'parent' as its 'parent',
 * and NULL children; and return its address.
 *
 * If allocating it in memory fails, this function just returns
 * NULL.
 *
 * @parent: parent of the new node
 * @value: What the 'n' int attribute of the new node will be
 *
 * Return: address of created node if the malloc was successful,
 * NULL otherwise.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value) {
	binary_tree_t *result = malloc(sizeof(binary_tree_t));

	/* malloc failed */
	if (result == NULL)
		return (NULL);

	result->n = value;
	result->parent = parent;

	return (result);
}

