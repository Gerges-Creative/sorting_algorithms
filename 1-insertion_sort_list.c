#include "sort.h"

/**
 * sort_swap - a function that swaps two nodes
 * @h: head node
 * @cur: current node for the insertion sort function
 * @prev: previous node for the insertion sort function
 * Return: the head node for the doubly linked list
 */
listint_t *sort_swap(listint_t **h, listint_t **cur, listint_t **prev)
{
	listint_t *node_c, *node_p;

	node_c = *cur;
	node_p = *prev;
	/* If there are just two nodes */
	if (node_p->prev == NULL && node_c->next == NULL)
	{
		node_c->next = node_p;
		node_p->prev = node_c;
		node_c->prev = NULL;
		node_p->next = NULL;
		*h = node_c;
	}
	/* First condition if node_p is the head */
	else if (node_p->prev == NULL)
	{
		node_c->next->prev = node_p;
		node_c->prev = NULL;
		node_p->next = node_c->next;
		*h = node_c;
	}
	/* Second condition if node_c is the tail */
	else if (node_c->next == NULL)
	{
		node_p->prev->next = node_c;
		node_c->prev = node_p->prev;
		node_p->next = NULL;
	}
	/* Third condition when between head and tail */
	else
	{
		node_p->prev->next = node_c;
		node_c->next->prev = node_p;
		node_p->next = node_c->next;
		node_c->prev = node_p->prev;
	}
	node_c->next = node_p;
	node_p->prev = node_c;
	return (*h);
}
/**
 * insertion_sort_list - a function that sorts a doubly linked list of
 * integers in ascending order using the Insertion Sort algorithm and then
 * prints the list after each swap.
 * @list: pointer that points to the doubly linked list
 * Return: no return value needed
 */
void insertion_sort_list(listint_t **list)
{
	/* node_c == current node, node_p == prev node, head == head node */
	listint_t *node_c, *node_p, *head;

	head = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node_c = (*list)->next;
	while (node_c != NULL)
	{
		node_p = node_c->prev;

		while (node_p != NULL && node_c->n < node_p->n)
		{
			/* Then swap the two nodes */
			/* & create all the neccessary links */
			/* through calling sort_swap function */
			sort_swap(&head, &node_c, &node_p);
			/* At the end of the if condition (reset list to the */
			/* head node) and then print list */
			/* The reset part has been modified to be an inner */
			/* and node_p take the value of the node_c->prev */
			/* so that when a node is smaller it keeps moving */
			/* untill it reachs its position */
			node_p = node_c->prev;
			print_list(head);
		}

		node_c = node_c->next;
	}

	*list = head;
}
