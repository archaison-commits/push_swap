#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	t_stack *current;
	t_stack *compare;
	size_t mistakes;
	size_t total_pairs;

	// Linked list, because why not.
	mistakes = 0;
	total_pairs = 0;
	current = a;
	if (!a || current->next == NULL)
		// Checks if there aren't enough elements to pair.
		return (0);
	while (current) // Bubble loop-> very bubble very loop;
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->value > compare->value)
				// alternative ((*current).value > (*compare).value) pointers <3.
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	return ((double)mistakes / total_pairs);
}
/*
#include "push_swap.h"
#include <stdio.h>


int	main(void)
{
	t_stack n1 = {1, NULL};
	t_stack n2 = {2, NULL};
	t_stack n3 = {3, NULL};
	t_stack n4 = {4, NULL};

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;

	printf("Disorder: %.2f\n", compute_disorder(&n1)); // somehow works.

	return (0);
}
*/
/*
function	compute_disorder(stack a):
mistakes = 0
total_pairs = 0
for i from 0 to size(a)-1:
	for j from i+1 to size(a)-1:
		total_pairs += 1
		if a[i] > a[j]:
			mistakes += 1
return mistakes / total_pairs
*/
