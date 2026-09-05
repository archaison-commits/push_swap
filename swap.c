/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 19:39:37 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/05 17:29:34 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swaping(t_stack **stack)
{
    t_stack *first;
    t_stack *second;

    if (!stack || !*stack || (*stack)->next == NULL)
        return ;
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

void	sa(t_stacks *stacks)
{
	swaping(&stacks->a);
	stacks->c_sa++;
	write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks)
{
	swaping(&stacks->b);
	stacks->c_sb++;
	write(1, "sb\n", 3);
}

void	ss(t_stacks *stacks)
{
	swaping(&stacks->a);
	swaping(&stacks->b);
	stacks->c_ss++;
	write(1, "ss\n", 3);
}

/*
int main(void)
{
    t_stack a;
    t_stack b;
    t_stack c;
    t_stacks stacks;

    a.value = 1;
    a.next = &b;

    b.value = 2;
    b.next = &c;
    c.value = 3;
    c.next = NULL;

    stacks.a = &a;

    printf("Before: %d %d %d\n",
        stacks.a->value,
        stacks.a->next->value,
        stacks.a->next->next->value);

    ss(&stacks);

    printf("After:  %d %d %d\n",
        stacks.a->value,
        stacks.a->next->value,
        stacks.a->next->next->value);

    return (0);
}*/
