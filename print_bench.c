/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 01:52:51 by brechied          #+#    #+#             */
/*   Updated: 2026/09/15 01:54:38 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*algorithm_type(double disorder)
{
	if (disorder < 0.2)
		return ("Adaptive O(n2)");
	if (disorder < 0.5)
		return ("Adaptive O(n√n)");
	return ("Adaptive O(n log n)");
}

static char	*strategy_name(t_strategy strategy, t_stacks *stacks)
{
	if (strategy == SIMPLE)
		return ("Simple O(n2)");
	if (strategy == MEDIUM)
		return ("Medium O(n√n)");
	if (strategy == COMPLEX)
		return ("Complex O(n log n)");
	return (algorithm_type(stacks->disorder));
}

void	print_bench(t_strategy strategy, t_stacks *stacks)
{
	printf("[bench] disorder: %.2f%%\n", stacks->disorder * 100);
	printf("[bench] strategy: %s\n", strategy_name(strategy, stacks));
	printf("[bench] total: %d\n", stacks->c_total);
	printf("[bench] sa: %d ", stacks->c_sa);
	printf("sb: %d ", stacks->c_sb);
	printf("ss: %d ", stacks->c_ss);
	printf("pa: %d ", stacks->c_pa);
	printf("pb: %d\n", stacks->c_pb);
	printf("[bench] ra: %d ", stacks->c_ra);
	printf("rb: %d ", stacks->c_rb);
	printf("rr: %d ", stacks->c_rr);
	printf("rra: %d ", stacks->c_rra);
	printf("rrb: %d ", stacks->c_rrb);
	printf("rrr: %d\n", stacks->c_rrr);
}
