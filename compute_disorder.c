/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 03:30:29 by brechied          #+#    #+#             */
/*   Updated: 2026/09/15 03:30:32 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stacks *stacks)
{
	t_stack	*current;
	t_stack	*compare;
	size_t	mistakes;
	size_t	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	if (!stacks || !stacks->a || stacks->a->next == NULL)
		return (0);
	current = stacks->a;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->value > compare->value)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	stacks->disorder = (double)mistakes / total_pairs;
	return (stacks->disorder);
}
