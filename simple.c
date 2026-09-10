/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:55:44 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/08 21:18:49 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_position(t_stack *stack)
{
	int	min;
	int	pos;
	int	posmin;

	min = stack->value;
	pos = 0;
	posmin = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			posmin = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (posmin);
}

void	simple_sort(t_stacks *stacks)
{
	int		minpos;
	int		size;

	while (stacks->a)
	{
		size = stack_size(stacks->a);
		minpos = min_position(stacks->a);
		if (minpos <= size / 2)
			while (minpos--)
				ra(stacks);
		else
		{
			minpos = size - minpos;
			while (minpos--)
				rra(stacks);
		}
		pb(stacks);
	}
	while (stacks->b)
		pa(stacks);
}