
#include "push_swap.h"
#include <stdio.h>

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
	char		**numbers;
	int			j;
	bool		bench;
	int			i;

	(void)argc;
	bench = false;
	strategy = UNDEFINE;
	j = 1;
	while (argv[j])
	{
		if (ft_strcmp(argv[j], "--bench") == 0)
			bench = true;
		else if (parsing_arg(argv[j]) != UNDEFINE)
			strategy = parsing_arg(argv[j]);
		else
			numbers = ft_split(argv[j], ' ');
		j++;
	}
	printf("Strategy: %d\n", strategy);
	printf("Bench: %s\n", bench ? "true" : "false");
	if (numbers)
	{
		printf("Numbers:\n");
		i = 0;
		while (numbers[i])
		{
			printf("  [%d] = %s\n", i, numbers[i]);
			i++;
		}
	}
	return (0);
}
// sa sb - ss √

// pa pb

// ra rb rr

// rra rrb rrr
