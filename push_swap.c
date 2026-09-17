/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 03:07:39 by brechied          #+#    #+#             */
/*   Updated: 2026/09/15 03:07:43 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_strategy	strategy;
	t_stacks	stacks;

	strategy = ADAPTIVE;
	stacks = (t_stacks){0};
	if (valid_arg(argc, argv) == ERROR)
		return (write(1, "ERROR\n", 6), ERROR);
	if (parse_args(argc, argv, &stacks, &strategy) == ERROR)
	{
		ft_lstclear(&stacks.a);
		return (write(1, "ERROR\n", 6), ERROR);
	}
	if (check_same_number(stacks.a) == ERROR)
	{
		ft_lstclear(&stacks.a);
		return (write(1, "ERROR\n", 6), ERROR);
	}
	choose_strategy(strategy, compute_disorder(&stacks), &stacks);
	if (stacks.bench)
		print_bench(strategy, &stacks);
	ft_lstclear(&stacks.a);
	ft_lstclear(&stacks.b);
	return (0);
}
