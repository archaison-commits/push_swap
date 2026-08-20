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
		return ;
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
	return (UNDEFINE);
}

int	main(int argc, char **argv)
{
	t_strategy	strategy;
	t_stack		*a;
	char		**numbers;
	size_t		j;
	bool		bench;

	bench = false;
	strategy = UNDEFINE;
	a = NULL;
	j = 1;
	while (j < argc)
	{
		if (ft_strcmp(argv[j], "--bench") == 0)
			bench = true;
		else if (parsing_arg(argv[j]) != UNDEFINE)
			strategy = parsing_arg(argv[j]);
		else if (ft_strchr(argv[j], ' '))
		{
			numbers = ft_split(argv[j], ' ');
			create_stack(&a, numbers);
			free_numbers(numbers);
		}
		else
			add_number(&a, argv[j]);
		j++;
	}
	return (0);
}
// sa sb - ss √

// pa pb

// ra rb rr

// rra rrb rrr
