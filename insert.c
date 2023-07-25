# include "sort.h"




/**
 * insertion_sort_list -  sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * print the list after each time you swap two elements
 *
 * @list: listint_t node pointer
 */

void insertion_sort_list(listint_t **list)
{
	int i, n, count = 0, j = 0;
	listint_t *node = NULL, *tmp = NULL, *node_next = NULL, *node_prev = NULL;
	int temp;
	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
                return;


	node = *list;
	while(node != NULL)
	{
		count++;
		node = node->next;
	}
	n = count;
	for (i = 1; i <= n; i++)
	{
		node = *list;
		j = 0;
		while(j < i)
		{
			j++;
			node = node->next;
		}
		tmp = node;
		temp = node->n;
		while ((node->prev != NULL) && (node->prev->n > temp))
		{
			node_prev = node->prev;
			if (node->next)
			{
				node_next = node->next;
				node_prev->next = node_next;
				node_next->prev = node_prev;
			}
			else
				node_prev->next = NULL;
			node = node_prev;
			tmp->next = node;
			if (node->prev == NULL)
			{
				tmp->prev = NULL;
				*list = tmp;
			}
			else
			{
				tmp->prev = node->prev;
				tmp->prev->next = tmp;
			}
			node->prev = tmp;
			node = tmp;
			print_list(*list);
		}

	}

}
