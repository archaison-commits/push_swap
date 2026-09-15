#include "push_swap.h"

double	compute_disorder(t_stacks *stacks)
{
	t_stack	*current;
	t_stack	*compare;
	size_t	mistakes;
	size_t	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	if (!stacks || !stacks->a || stacks->a->next == NULL)
		return (0);
	current = stacks->a;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->value > compare->value)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	stacks->disorder = (double)mistakes / total_pairs;
	return (stacks->disorder);
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
