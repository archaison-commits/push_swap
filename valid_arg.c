/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 20:44:38 by brechied          #+#    #+#             */
/*   Updated: 2026/08/31 20:44:41 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	has_digit(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]))
			return (SUCCESS);
		i++;
	}
	return (ERROR);
}

int	check_same_number(t_stack *a)
{
	t_stack	*current;
	t_stack	*compare;

	current = a;
	if (!a || current->next == NULL)
		return (0);
	while (current)
		{
		compare = current->next;
		while (compare)
		{
			if (current->value == compare->value)
				return (ERROR);
			compare = compare->next;
		}
		current = current->next;
	}
	return (SUCCESS);
}

int	validate_numbers(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (is_valid_flag(argv[i]))
			i++;
		if (is_valid_number(argv[i]) || ft_strchr(argv[i], ' '))
			i++;
		else
			return (ERROR);
	}
	return (SUCCESS);
}

int	is_valid_flag(char *arg)
{
	return (ft_strcmp(arg, "--adaptive") == 0
		|| ft_strcmp(arg, "--medium") == 0
		|| ft_strcmp(arg, "--simple") == 0
		|| ft_strcmp(arg, "--complex") == 0
		|| ft_strcmp(arg, "--bench") == 0);
}

int	valid_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if ((is_valid_flag(argv[i])) || (is_valid_number(argv[i])))
			i++;
		else
			return (ERROR);
	}
	return (SUCCESS);
}
