/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:51:44 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/05 17:30:21 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack **stack)
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
	reverse(&stacks->a);
	stacks->c_rra++;
	write(1, "rra\n", 4);		
}

void	rrb(t_stacks *stacks)
{
	reverse(&stacks->b);
	stacks->c_rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(t_stacks *stacks)
{
	reverse(&stacks->a);
	reverse(&stacks->b);
	stacks->c_rrr++;
	write(1, "rrr\n", 4);
}

/*int main(void)
{
    t_stacks stacks;

    stacks.a = malloc(sizeof(t_stack) * 4);

    stacks.a[0].value = 1;
    stacks.a[0].next = &stacks.a[1];
    stacks.a[1].value = 2;
    stacks.a[1].next = &stacks.a[2];
    stacks.a[2].value = 3;
    stacks.a[2].next = &stacks.a[3];
    stacks.a[3].value = 4;
    stacks.a[3].next = NULL;

    stacks.c_rra = 0;

    printf("przed: %d %d %d %d\n",
        stacks.a->value,
        stacks.a->next->value,
        stacks.a->next->next->value,
        stacks.a->next->next->next->value);

    rra(&stacks);

    printf("po:    %d %d %d %d\n",
        stacks.a->value,
        stacks.a->next->value,
        stacks.a->next->next->value,
        stacks.a->next->next->next->value);

    free(stacks.a);

    return (0);
}*/
