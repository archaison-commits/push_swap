/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:07:31 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/08 21:12:04 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	t_stack	*headb;
	t_stack	*heada;
	t_stack	*tmp;

	if (!stacks || stacks->b == NULL)
		return ;
	headb = stacks->b;
	heada = stacks->a;
	tmp = headb->next;
	headb->next = heada;
	stacks->b = tmp;
	stacks->a = headb;
	stacks->c_pa++;
	stacks->c_total++;
	write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks)
{
	t_stack	*headb;
	t_stack	*heada;
	t_stack	*tmp;

	if (!stacks || stacks->a == NULL)
		return ;
	headb = stacks->b;
	heada = stacks->a;
	tmp = heada->next;
	heada->next = headb;
	stacks->a = tmp;
	stacks->b = heada;
	stacks->c_pb++;
	stacks->c_total++;
	write(1, "pb\n", 3);
}
