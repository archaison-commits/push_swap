/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:51:44 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/08 21:09:21 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	if (!stack || !*stack || (*stack)->next == NULL)
		return ;
	last = *stack;
	last = ft_lstlast(last);
	first = *stack;
	tmp = *stack;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = first;
	*stack = last;
}

void	rra(t_stacks *stacks)
{
	if (!stacks)
		return ;
	reverse(&stacks->a);
	stacks->c_rra++;
	stacks->c_total++;
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *stacks)
{
	if (!stacks)
		return ;
	reverse(&stacks->b);
	stacks->c_rrb++;
	stacks->c_total++;
	write(1, "rrb\n", 4);
}

void	rrr(t_stacks *stacks)
{
	if (!stacks)
		return ;
	reverse(&stacks->a);
	reverse(&stacks->b);
	stacks->c_rrr++;
	stacks->c_total++;
	write(1, "rrr\n", 4);
}