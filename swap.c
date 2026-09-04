/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 19:39:37 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/04 21:18:38 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
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
	stacks->c_sa++;
	write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*second;
	
	if(!stacks || stacks->a == NULL || stacks->a->next == NULL)
		return ;
	first = stacks->b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stacks->a = second;
	stacks->c_sb++;
	write(1, "sb\n", 3);
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
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
