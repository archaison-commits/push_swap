/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 20:43:44 by brechied          #+#    #+#             */
/*   Updated: 2026/09/11 03:35:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>

void	free_numbers(char **numbers)
{
	size_t	i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

int	add_number(t_stack **a, char *str)
{
	t_stack	*new_node;
	int		value;

	if (!is_valid_number(str))
		return (ERROR);
	value = ft_atoi(str);
	new_node = ft_lstnew(value);
	if (!new_node)
		return (ERROR);
	ft_lstadd_back(a, new_node);
	return (SUCCESS);
}

void	create_stack(t_stack **a, char **numbers)
{
	size_t	i;

	i = 0;
	while (numbers[i])
	{
		add_number(a, numbers[i]);
		i++;
	}
}

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
		if (disorder < 0.2)
			simple_sort(stacks);
		else if (disorder >= 0.2 && disorder < 0.5)
			medium_sort(stacks);
		else if (disorder >= 0.5)
			complex_sort(stacks);
	}

}

int	parse_args(int argc, char **argv, t_stacks *stacks,
		t_strategy *strategy, bool *bench)
{
	int		i;
	char	**numbers;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			*bench = true;
		else if (parsing_strategy(argv[i]) != ADAPTIVE)
			*strategy = parsing_strategy(argv[i]);
		else if (ft_strchr(argv[i], ' '))
		{
			numbers = ft_split(argv[i], ' ');
			create_stack(&stacks->a, numbers);
			free_numbers(numbers);
		}
		else
			add_number(&stacks->a, argv[i]);
		i++;
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_strategy	strategy;
	t_stacks	stacks;
	bool		bench;

	stacks.a = NULL;
	stacks.b = NULL;
	strategy = ADAPTIVE;
	bench = false;

	if (valid_arg(argc, argv) == ERROR)
		return (write(1, "ERROR\n", 5), ERROR);
	if (parse_args(argc, argv, &stacks, &strategy, &bench) == ERROR)
		return (write(1, "ERROR\n", 5), ERROR);
	if (check_same_number(stacks.a) == ERROR)
	{
		ft_lstclear(&stacks.a);
		return (write(1, "ERROR\n", 5), ERROR);
	}
	choose_strategy(strategy, compute_disorder(stacks.a), &stacks);
	ft_lstclear(&stacks.a);
	return (0);
}
