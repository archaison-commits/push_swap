/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 20:01:08 by brechied          #+#    #+#             */
/*   Updated: 2026/08/31 20:45:57 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mem_all(char **array, int pos, size_t size)
{
	int	i;

	array[pos] = malloc(size);
	if (array[pos] == NULL)
	{
		i = 0;
		while (i < pos)
		{
			free(array[i]);
			i++;
		}
		free(array);
		return (1);
	}
	return (0);
}

int	words_cpy(char **array, char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (!*s)
			break ;
		len = 0;
		while (s[len] != c && s[len])
			len++;
		if (mem_all(array, i, len + 1))
			return (1);
		ft_strlcpy(array[i], s, len + 1);
		i++;
		s += len;
	}
	array[i] = NULL;
	return (0);
}

size_t	count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			words++;
			while (*s != c && *s)
				s++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = 0;
	words = count_words(s, c);
	array = malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array[words] = NULL;
	if (words_cpy(array, s, c))
		return (NULL);
	return (array);
}
/*
int	main(void)
{
	char	*s;
	char	**a;

	s = "Hello send me to the hospital, mate!";
	a = ft_split(s, ' ');
	while (*a)
		printf("%s\n", *a++);
	return (0);
}*/
