/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:17:27 by brechied          #+#    #+#             */
/*   Updated: 2026/08/18 21:48:31 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/*
int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "helloooooooooooooooooooooooooo";
	str2 = "helloooooooooooooooooooooooooo0";
	printf("%s\n%s\nft_strcmp -> %d\nstrcmp-> %d\n\n\n",
       	str1, str2, ft_strcmp(str1, str2), strcmp(str1, str2));
	printf("s1: %d\n", ft_strcmp(str1, str2));
	return (0);
}*/
