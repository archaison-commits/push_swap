/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:30:37 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/04 01:37:08 by mniwinsk         ###   ########.fr       */
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

void	mediumsort(t_stacks *stacks)
{
	int	size;
	int	chunk;
	int minpos;
	int	i;

	size = stacksize(stacks->a);
	chunk = ft_sqrt(size);
	indexing(stacks->a);
	i = 0;
	while (stacks->a)
	{
		if (stacks->a->index < chunk)
			pb(stacks);
		else if (stacks->a->next->index < chunk)
			sa(stacks);
		else if (stacks->a->index <= (size - i) / 2 )
			ra(stacks);
		else
			rra(stacks); 
		chunk += ft_sqrt(size);
		i++;
	}
	while (stacks->b)
	{
		if (stacks->b->index == size)
		{
			pa(stacks);	
			size--;
		}
	}
}
