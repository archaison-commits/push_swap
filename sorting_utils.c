/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:48:56 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/08 21:08:07 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	stsize;

	stsize = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		stsize++;
	}
	return (stsize);
}

int	min_value(t_stack *stack)
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
	t_stack	*stack;
	int		min;
	int		idx;
	int		size;

	size = stack_size(stacks->a);
	idx = 0;
	tmp = stacks->a;
	while (idx < size)
	{
		min = min_value(tmp);
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