/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 17:00:20 by brechied          #+#    #+#             */
/*   Updated: 2026/07/21 17:00:22 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_ft(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		len++;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int	ft_putnbr_un(unsigned int n)
{
	int	len;

	len = len_ft(n);
	if (n > 9)
		ft_putnbr_un(n / 10);
	write(1, &(char){n % 10 + '0'}, 1);
	return (len);
}
