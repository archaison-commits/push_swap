
#include "push_swap.h"

t_stack	*value_swap(t_stack *node)
{
	if (!node)
		return (0);
	if (node-> next)
		node = node->next;
	return (node);
}
