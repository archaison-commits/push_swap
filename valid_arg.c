# include "push_swap.h"

int	is_same_number(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*number;

	i = 0;
	j = 0;
	k = 0;
	while (i++ < argc)
	{
		if (argv[i] == ' ')
			continue;
		number = argv[i];
		while (number[k] && !(number[k + 1] == ' '))
			k++;
		while (argv[j++])
		{

		}

	}
}

int validate_numbers(int argc, char **argv)
{
	size_t	i;

	i= 0;
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
