/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 19:39:37 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/08/19 01:15:48 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	value_swap(t_stacks *stacks)
{
	t_stack *first;
	t_stack	*second;
	
	if (!stacks || stacks->a == NULL || stacks->a->next == NULL)
		return ;
	first = stacks->a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stacks->a = second;
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

    value_swap(&stacks);

    printf("After:  %d %d %d\n",
        stacks.a->value,
        stacks.a->next->value,
        stacks.a->next->next->value);

    return (0);
}*/
