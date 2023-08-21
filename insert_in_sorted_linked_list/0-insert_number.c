#include "lists.h"
#include <stdlib.h>

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *number_node = malloc(sizeof(listint_t));
	listint_t **current = head;

	if (number_node == NULL) {
                return (NULL);
	}

	while (*current && (**current).n < number) {
		current = &(**current).next;
	}

	number_node->n = number;
	number_node->next = (**current).next;

	*current = number_node;

	return (number_node);
}

