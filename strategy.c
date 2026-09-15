/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 03:14:42 by brechied          #+#    #+#             */
/*   Updated: 2026/09/15 22:06:30 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_strategy	parsing_strategy(char *arg)
{
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (ADAPTIVE);
	else if (ft_strcmp(arg, "--simple") == 0)
		return (SIMPLE);
	else if (ft_strcmp(arg, "--medium") == 0)
		return (MEDIUM);
	else if (ft_strcmp(arg, "--complex") == 0)
		return (COMPLEX);
	return (ADAPTIVE);
}

void	choose_strategy(t_strategy strat, double disorder, t_stacks *stacks)
{
	if (strat == SIMPLE)
		simple_sort(stacks);
	else if (strat == MEDIUM)
		medium_sort(stacks);
	else if (strat == COMPLEX)
		complex_sort(stacks);
	if (strat == ADAPTIVE)
	{
		if (disorder == 0)
			return ;
		if (ft_lstsize(stacks->a) == 5)
			simple_sort(stacks);
		else if (disorder < 0.2)
			simple_sort(stacks);
		else if (disorder >= 0.2 && disorder < 0.5)
			medium_sort(stacks);
		else if (disorder >= 0.5)
			complex_sort(stacks);
	}
}
