# include "push_swap.h"

int	valid_arg(int	argc, char **argv)
{
	size_t	i;
	size_t	errors;

	i = 1;
	errors = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--adaptive") == 0)
			return (1);
		else if (ft_strcmp(argv[i], "--simple") == 0)
			return (1);
		else if (ft_strcmp(argv[i], "--medium") == 0)
			return (1);
		else if (ft_strcmp(argv[i], "--complex") == 0)
			return (1);
		else if (ft_strcmp(argv[i], "--bench") == 0)
			return (1);

	return (0);
	}

}
