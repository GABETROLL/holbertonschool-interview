#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * add_nodeint_start - Adds a new node of type
 * 'listint_t', at the beggining of '*head'
 * (making the new node's 'next' be '*head'
 * and replacing '*head' with the new node pointer).
 * This function then returns that node.
 * THE NODE MUST BE FREED WITH
 * free(<returned node address>)
 *
 * @head: pointer to pointer of the head node of
 * the linked list of type 'listint_t'.
 *
 * (I think visualizing the pointer to each node
 * as part of the node itself makes it easier to think
 * about this problem)
 *
 * IF 'head' IS NULL, THIS FUNCTION JUST RETURNS NULL
 * BEFORE DOING ANTHING.
 *
 * @n: 'n' value of new node
 *
 * Return: address of the new node, or NULL if
 * this function failed.
 * IF THE RETURNED NODE ADDRESS ISN'T NULL,
 * THE MEMORY SPACE FOR THE NODE MUST BE FREED
 * WITH free(<returned node address>)
 */
listint_t *add_nodeint_start(listint_t **head, const int n)
{
	listint_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(listint_t));

	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;

	*head = new;

	return (new);
}

/**
 * is_palindrome - Calculates
 * weather or not '*head' is a palindrome.
 * If we go through each node in '*head',
 * and we make anothe linked list that's the
 * reverse of '*head', we can then make
 * a liner scan of '*head' and the reversed list,
 * and check if they match.
 *
 * @head: pointer to pointer of the head node of
 * the linked list of type 'listint_t'.
 * (I think visualizing the pointer to each node
 * as part of the node itself makes it easier to think
 * about this problem)
 * IF 'head' IS NULL, THIS FUNCTION JUST RETURNS NULL
 * BEFORE DOING ANTHING.
 *
 * Return: 1 if the linked list in '*head'
 * is the same when reversed,
 * 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
	/* reversed version of '*head' */
	listint_t *reversed = NULL;
	/* for scanning the original linked list and the reversed one */
	listint_t **original_node;
	listint_t **reversed_node;

	if (!head || !(*head))
		return (0);
	/*
	 * BUILD a reversed version of '*head'
	 * stored in '*reversed'
	 */
	original_node = head;
	while (*original_node)
	{
		add_nodeint_start(&reversed, (*original_node)->n);
		original_node = &((*original_node)->next);
	}
	/*
	 * Comparing the reversed sequence with the original.
	 * Returns 1 if all of the n's match, and 0 if they dont'.
	 */
	original_node = head;
	reversed_node = &reversed;
	/* If we reached the end of one, the other one should have ended too */
	while ((*original_node) && (*reversed_node))
	{
		if ((*original_node)->n != (*reversed_node)->n)
			return (0);

		original_node = &((*original_node)->next);
		reversed_node = &((*reversed_node)->next);
	}
	if (*original_node || *reversed_node)
	{
		fputs("Original and reversed have different lengths!!!", stderr);
		exit(1);
	}
	return (1);
}

