/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:48:56 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/03 22:23:04 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minvalue(t_stack *stack)
{
	int	min;

	while (stack && stack->index != -1)
		stack = stack->next;
	if (!stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min && stack->index == -1)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	indexing(t_stacks *stacks)
{
	t_stack	*tmp;
	t_stack *stack;
	int		min;
	int		idx;
	int		size;

	size = stacksize(stacks->a);
	idx = 0;
	tmp = stacks->a;
	while (idx < size)
	{
		min = minvalue(tmp);
		stack = tmp;
		while (stack)
		{
			if (stack->value == min)
			{
				stack->index = idx;
				break ;
			}
			stack = stack->next;
		}
		idx++;
	}
}

/*
int main(void)
{
    t_stacks stacks;
    t_stack a;
    t_stack b;
    t_stack c;
    t_stack d;
    t_stack e;
    t_stack *tmp;

    a.value = 42;
    a.index = -1;
    a.next = &b;

    b.value = 10;
    b.index = -1;
    b.next = &c;

    c.value = 35;
    c.index = -1;
    c.next = &d;

    d.value = 7;
    d.index = -1;
    d.next = &e;

    e.value = 25;
    e.index = -1;
    e.next = NULL;

    stacks.a = &a;
    stacks.b = NULL;

    printf("PRZED:\n");
    tmp = stacks.a;
    while (tmp)
    {
        printf("value: %d, index: %d\n", tmp->value, tmp->index);
        tmp = tmp->next;
    }

    indexing(&stacks);

    printf("\nPO:\n");
    tmp = stacks.a;
    while (tmp)
    {
        printf("value: %d, index: %d\n", tmp->value, tmp->index);
        tmp = tmp->next;
    }

    return (0);
}
*/
