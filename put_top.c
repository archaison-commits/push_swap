#include "push_swap.h"

t_stack	*value_swap(t_stack *dest, t_stack *src)
{
	t_stack	*new_node;

	if (!src)
		return (0);
	new_node = src->value;
	dest = new_node;
	free(src->value);
	free(src);
	return (dest);
}

int	main(void)
{
	t_stack	*src;
	t_stack	*dest;
	t_stack	*result;

	src = malloc(sizeof(t_stack));
	dest = NULL;

	src->value = 42;
	src->next = NULL;

	printf("Before:\n");
	printf("src->value  = %d\n", src->value);
	printf("dest        = %p\n", (void *)dest);

	result = value_swap(dest, src);

	printf("\nAfter:\n");
	printf("result      = %p\n", (void *)result);

	if (result)
		printf("result->value = %d\n", result->value);

	return (0);
}
