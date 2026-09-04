/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:30:37 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/05 00:24:12 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	if (nb == 1)
		return (1);
	if (nb == 0 || nb < 0)
		return (0);
	i = 1;
	while (i * i < nb)
	{
		if (i * i == nb)
			return (i);
		if ((i + 1) * (i + 1) > nb)
			return (i + 1);
		i++;
	}
	return (i);
}

int	indexposition(t_stack *stack, int chunksize)
{
	int pos;
	int idxpos;

	pos = 0;
	while (stack->next != NULL)
	{
		if (stack->index < chunksize)
		{
			idxpos = pos;
			break ;
		}
		stack = stack->next;
		pos++;
	}
	if (stack->index >= chunksize)
		return (-1);
	return (idxpos);
}

void	checker(t_stacks *stacks, int size, int idxpos, int chunk)
{
	if (stacks->a->index >= chunk && stacks->a->next->index < chunk)
		sa(stacks);
	if (idxpos <= size / 2)
		ra(stacks);
	if (idxpos > size / 2)
		rra(stacks);
	if (stacks->a->index < chunk)
		pb(stacks);
	if (stacks->b->index == size)
		pa(stacks);
	if (stacks->b->index < size && stack->b->next->index == size)
		sb(stacks);
	if (stacks->b->index < stacks->b->next->index
		&& stacks->a>index < stacks->a->next->index)
		ss(stacks);
}

void	mediumsort(t_stacks *stacks)
{
	int	idxpos;
	int	chunk;
	int	size;
	int	chunksize;
	
	size = stacksize(stacks->a);
	chunksize = ft_sqrt(size);
	chunk = ft_sqrt(size);
	indexing(stacks->a);
	while (stacks->a)
	{
		idxpos = indexposition(stacks->a, chunk);
		size = stacksize(stacks->a);
		if (idxpos == -1)
			chunk += chunksize;
		else
			checker(stacks->a, size, idxpos, chunk);
	}
	chunk -= chunksize;
	while (stacks->b)
	{
		size = stacksize(stacks->b);
		idxpos = indexposition(stacks->b, chunk);
		checker(stacks->b, size, idxpos, chunk);
	}
}
