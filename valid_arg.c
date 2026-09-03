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

char	*cpy_number(char *s1, int length)
{
	size_t	i;
	char	*new_str;

	i = 0;
	while (s1[i] && new_str[i])
		new_str[++i] = s1[i];
	return (new_str);
}

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

int	string_number(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		while (arg[i] == ' ')
			i++;
		if (!arg[i])
			break ;
		if (ft_isdigit(arg[i]))
			i++;
		else if ((arg[i] == '-' || arg[i] == '+')
			&& ft_isdigit(arg[i + 1])
			&& (i == 0 || arg[i - 1] == ' '))
			i++;
		else
			return (ERROR);
	}
	return (SUCCESS);
}

int	check_same_number(t_stack *a)
{
	t_stack	*current;
	t_stack	*compare;

	// Linked list, because why not.
	current = a;
	if (!a || current->next == NULL)
		// Checks if there aren't enough elements to pair.
		return (0);
	while (current) // Bubble loop-> very bubble very loop;
	{
		compare = current->next;
		while (compare)
		{
			if (current->value == compare->value)
				return (free_stack(&a)(ERROR));
			compare = compare->next;
		}
		current = current->next;
	}
	return (SUCCESS);
}
/*
int	is_same_number(int argc, char **argv)
{
	size_t	i;
	size_t	num_l;
	size_t	start;
	size_t	length;
	char	*number;

	i = 1;
	num_l = 0;
	start = 0;
	number = argv[i];
	while (number[num_l])
	{
		while (number[num_l] == ' ')
			num_l++;
		if (!number[num_l])
			break ;
		start = num_l;
		while (number[num_l] && number[num_l] != ' ')
			num_l++;
		length = num_l - start;
		while (argv[i])
		{
			if (check_same_number_arg(argv[i++], number, start, length) == ERROR)
			{}
		}
	}
}
*/
int	validate_numbers(int argc, char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (is_valid_flag(argv[i]))
			i++;
		if (is_valid_number(argv[i]) || ft_strchr(argv[i], ' '))
			i++;
	}

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
