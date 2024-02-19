#include "sort.h"

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
	*list = (*list)->next;

	while (*list != NULL)
	{
		node_c = *list;
		node_p = (*list)->prev;

		if (node_p != NULL && node_c->n < node_p->n)
		{
			/* Then swap the two nodes */
			/* & create all the neccessary links */

			/* First condition if node_p is the head */
			if (node_p->prev == NULL)
			{
				node_c->next->prev = node_p;
				node_c->prev = NULL;
				node_p->next = node_c->next;
				head = node_c;
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
			/* At the end of the if condition reset list to the */
			/* head node and then print list */
			*list = head;
			print_list(*list);
		}

		*list = (*list)->next;
	}

	*list = head;
}