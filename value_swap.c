
#include "push_swap.h"

t_stack	*value_swap(t_stack *node)
{
	t_stack	*first;
	t_stack	*second;

	if (!node)
		return (0);
	first = node;
	second = node->next;
	node->next = first;
	node = second;
	return (node);
}
