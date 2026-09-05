/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:30:37 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/05 20:15:06 by mniwinsk         ###   ########.fr       */
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
	int	pos;
	int	idxpos;

	pos = 0;
	while (stack)
	{
		if (stack->index < chunksize)
		{
			idxpos = pos;
			break ;
		}
		stack = stack->next;
		pos++;
	}
	if (!stack || stack->index >= chunksize)
		return (-1);
	return (idxpos);
}

void	push_swap_rotate_a(t_stacks *stacks, int size, int idxpos, int chunk)
{
	if (stacks->a->index >= chunk && stacks->a->next->index < chunk)
	{
		sa(stacks);
		pb(stacks);
		return ;
	}
	if (stacks->a->index < chunk)
		pb(stacks);
	else if (idxpos <= size / 2)
		ra(stacks);
	else
		rra(stacks);
}

void	pushing_swaping_rotating_b(t_stacks *stacks, int size, int chunk)
{
	int		i;
	t_stack	*tmp;
	
	i = 0;
	if (!stacks->b)
		return ;
	tmp = stacks->b;
	while (tmp->index != chunk)
	{
		tmp = tmp->next;
		i++;
	}
	if (i == 1)
		sb(stacks);
	else if (i <= size / 2)
		while (i--)
			rb(stacks);
	else
	{
		i = size - i;
		while (i--)
			rrb(stacks);
	}
	pa(stacks);
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
	indexing(stacks);
	while (stacks->a)
	{
		idxpos = indexposition(stacks->a, chunk);
		size = stacksize(stacks->a);
		if (idxpos == -1)
			chunk += chunksize;
		else
			push_swap_rotate_a(stacks, size, idxpos, chunk);
	}
	chunk = stacksize(stacks->b) - 1;
	while (stacks->b)
	{
		size = stacksize(stacks->b);
		pushing_swaping_rotating_b(stacks, size, chunk);
		chunk--;
	}
}
