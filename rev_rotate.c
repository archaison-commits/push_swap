/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:51:44 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/08/19 15:51:17 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	if (!stacks || stacks->a == NULL || stacks->a->next == NULL)
		return ;
	last = stacks->a;
	last = ft_lstlast(last);
	first = stacks->a;
	tmp = stacks->a;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = first;
	stacks->a = last;
	stacks->c_rra++;
	write(1, "rra", 3);		
}

void	rrb(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*last;
	t_stack *tmp;
	
	if (!stacks || stacks->b == NULL || stacks->b->next == NULL)
		return ;
	last = stacks->b;
	last = ft_lstlast(last);
	first = stacks->b;
	tmp = stacks->b;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = first;
	stacks->b = last;
	stacks->c_rrb++;
	write(1, "rrb", 3);
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
	stacks->c_rrr++;
	write(1, "rrr", 3);
}

int main(void)
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
}
