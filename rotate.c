/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:09:56 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/05 17:31:26 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotating(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	if (!stack || !*stack || (*stack)->next == NULL)
		return ;
	last = *stack;
	last = ft_lstlast(last);
	first = *stack;
	tmp = first->next;
	first->next = last->next;
	last->next = first;
	*stack = tmp;
}

void	ra(t_stacks *stacks)
{
	rotating(&stacks->a);
	stacks->c_ra++;
	write(1, "ra\n", 3);
}
void	rb(t_stacks *stacks)
{
	rotating(&stacks->b);
	stacks->c_rb++;
	write(1, "rb\n", 3);
}

void	rr(t_stacks *stacks)
{
	rotating(&stacks->a);
	rotating(&stacks->b);
	stacks->c_rr++;
	write(1, "rr\n", 3);
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
