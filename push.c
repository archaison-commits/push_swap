/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:07:31 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/02 12:17:53 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	t_stack *headb;
	t_stack *heada;
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
	write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks)
{
	t_stack *headb;
	t_stack	*heada;
	t_stack	*tmp;
	
	if (!stacks || stacks->a == NULL)
		return ;
	headb = stacks->b;
	heada = stacks->a;
	tmp = heada->next;
	heada->next	= headb;
	stacks->a = tmp;
	stacks->b = heada;
	stacks->c_pb++;
	write(1, "pb\n", 3);
}
/*
int main(void)
{
    t_stacks stacks;
    t_stack a1;
    t_stack a2;
    t_stack b1;
    t_stack b2;

    a1.value = 1;
    a1.next = &a2;

    a2.value = 2;
    a2.next = NULL;

    b1.value = 3;
    b1.next = &b2;

    b2.value = 4;
    b2.next = NULL;

    stacks.a = &a1;
    stacks.b = &b1;

    printf("Before:\n");
    printf("A: %d -> %d\n", stacks.a->value, stacks.a->next->value);
    printf("B: %d -> %d\n", stacks.b->value, stacks.b->next->value);

    pa(&stacks);

    printf("\nAfter pa:\n");
    printf("A: %d -> %d -> %d\n",
        stacks.a->value,
        stacks.a->next->value,
        stacks.a->next->next->value);
    printf("B: %d\n", stacks.b->value);
	printf("c_pa: %d\n", stacks.c_pa);
    return (0);
}*/
