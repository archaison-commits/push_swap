/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 20:43:44 by brechied          #+#    #+#             */
/*   Updated: 2026/08/31 20:44:01 by brechied         ###   ########.fr       */
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

void	add_number(t_stack **a, char *str)
{
	t_stack	*new_node;
	int		value;

	if (!is_valid_number(str))
		return (ERROR);
	value = ft_atoi(str);
	new_node = ft_listnew(value);
	ft_lstadd_back(a, new_node);
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

t_strategy	parsing_arg(char *arg)
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

int	main(int argc, char **argv)
{
	t_strategy	strategy;
	t_stack		*a;
	char		**numbers;
	size_t		i;
	bool		bench;

	bench = false;
	strategy = ADAPTIVE;
	a = NULL;
	i = 1;
	if (valid_arg(argc, argv) == ERROR)
		return (ERROR);
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			bench = true;
		else if (parsing_arg(argv[i]) != ADAPTIVE)
			strategy = parsing_arg(argv[i]);
		else if (ft_strchr(argv[i], ' '))
		{
			numbers = ft_split(argv[i], ' ');
			create_stack(&a, numbers);
			free_numbers(numbers);
		}
		else
			add_number(&a, argv[i]);
		i++;
	}
	return (0);
}
// sa sb - ss √

// pa pb

// ra rb rr

// rra rrb rrr
