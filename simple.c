/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:55:44 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/02 12:20:28 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacksize(t_stack *stack)
{
	int stsize;

	stsize = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		stsize++;
	}
	return (stsize);
}

int	minposition(t_stack *stack)
{
	int	min;
	int pos;
	int posmin;

	min = stack->value;
	pos = 0;
	posmin = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			posmin = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (posmin);
}

void	simplesort(t_stacks *stacks)
{
	int		minpos;
	int		size;
	
	while (stacks->a)
	{
		size = stacksize(stacks->a);
		minpos = minposition(stacks->a);
		if (minpos <= size / 2)
			while (minpos--)
				ra(stacks);
		else
		{
			minpos = size - minpos;
			while (minpos--)
				rra(stacks);
		}
		pb(stacks);
	}
	while (stacks->b)
		pa(stacks);
}

/*
int main(int argc, char **argv)
{
    t_stacks   stacks;
    t_stack    *new;
    t_stack    *last;
    int        i;

    if (argc < 2)
        return (0);

    stacks.a = NULL;
    stacks.b = NULL;

    i = 1;
    while (i < argc)
    {
        new = malloc(sizeof(t_stack));
        if (!new)
            return (1);

        new->value = atoi(argv[i]);
        new->index = 0;
        new->next = NULL;

        if (!stacks.a)
            stacks.a = new;
        else
        {
            last = stacks.a;
            while (last->next)
                last = last->next;
            last->next = new;
        }
        i++;
    }

    printf("BEFORE\n");
    printf("A: ");

    new = stacks.a;
    while (new)
    {
        printf("%d ", new->value);
        new = new->next;
    }
    printf("\n");

    printf("B: ");

    new = stacks.b;
    while (new)
    {
        printf("%d ", new->value);
        new = new->next;
    }
    printf("\n\n");

    simplesort(&stacks);

    printf("AFTER\n");
    printf("A: ");

    new = stacks.a;
    while (new)
    {
        printf("%d ", new->value);
        new = new->next;
    }
    printf("\n");

    printf("B: ");

    new = stacks.b;
    while (new)
    {
        printf("%d ", new->value);
        new = new->next;
    }
    printf("\n");

    return (0);
}
*/
