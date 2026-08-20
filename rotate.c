/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:09:56 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/08/19 14:50:50 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	if (!stacks || stacks->a == NULL || stacks->a->next == NULL)
		return ;
	last = stacks->a;
	last = ft_lstlast(last);
	first = stacks->a;
	tmp = first->next;
	first->next = last->next;
	last->next = first;
	stacks->a = tmp;
	stacks->c_ra++;
	write(1, "ra", 2);
}

void	rb(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;
	
	if (!stacks || stacks->a == NULL || stacks->a->next == NULL)
		return	;
	last = stacks->b;
	last = ft_lstlast(last);
	first = stacks->b;
	tmp = first->next;
	first->next = last->next;
	last->next = first;
	stacks->b = tmp;
	stacks->c_rb++;
	write(1, "rb", 2);
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
	stacks->c_rr++;
	write(1, "rr", 2);
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

    ra(&stacks);

    printf("After:  %d %d %d\n",
        stacks.a->value,
        stacks.a->next->value,
        stacks.a->next->next->value);

    return (0);
}
*/
