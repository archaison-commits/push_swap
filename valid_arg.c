# include "push_swap.h"

size_t	valid_arg(int	argc, char **argv)
{
	size_t	i;
	size_t	ERROR;

	i = 1;
	errors = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if ((ft_strcmp(argv[i], "--adaptive") == 0)
				|| (ft_strcmp(argv[i], "--medium")
				|| (ft_strcmp(argv[i], "--simple")
				|| (ft_strcmp(argv[i], "--complex")
			{
				i++;
				continue;
			}
		}
		return ()


	return (0);
	}

}
