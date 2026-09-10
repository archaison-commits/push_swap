/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:38:08 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/08 21:20:33 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	how_many_bits(int size)
{
	int	i;

	i = 0;
	while (size)
	{
		size = size >> 1;
		i++;
	}
	return (i);
}

void	complex_sort(t_stacks *stacks)
{
	int	size;
	int	bits;
	int	i;
	int	j;

	indexing(stacks);
	size = stack_size(stacks->a);
	bits = how_many_bits(size - 1);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stacks->a->index >> i) & 1) == 0)
				pb(stacks);
			else
				ra(stacks);
			j++;
		}
		while (stacks->b)
			pa(stacks);
		i++;
	}
}
