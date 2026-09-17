/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 20:42:23 by brechied          #+#    #+#             */
/*   Updated: 2026/08/31 20:42:30 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		while (ft_strchr(&str[i], ' '))
			i++;
		if (!ft_isdigit(str[i]))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	parse_args(int argc, char **argv, t_stacks *stacks,
		t_strategy *strategy)
{
	int		i;
	char	**numbers;

	stacks->bench = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			stacks->bench = true;
		else if (is_valid_flag(argv[i]))
			*strategy = parsing_strategy(argv[i]);
		else if (ft_strchr(argv[i], ' '))
		{
			numbers = ft_split(argv[i], ' ');
			if (create_stack(&stacks->a, numbers) == ERROR)
				return (free_numbers(numbers), ERROR);
			free_numbers(numbers);
		}
		else
			if (add_number(&stacks->a, argv[i]) == ERROR)
				return (ERROR);
		i++;
	}
	return (SUCCESS);
}

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
	t_stack		*new_node;
	long		value;

	if (is_valid_number(str) == ERROR)
		return (ERROR);
	value = ft_atoi(str);
	if (value > INT_MAX || value < INT_MIN)
		return (ERROR);
	new_node = ft_lstnew(value);
	if (!new_node)
		return (ERROR);
	ft_lstadd_back(a, new_node);
	return (SUCCESS);
}

int	create_stack(t_stack **a, char **numbers)
{
	size_t	i;

	i = 0;
	while (numbers[i])
	{
		if (add_number(a, numbers[i]) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
