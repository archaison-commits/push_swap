/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:31:45 by brechied          #+#    #+#             */
/*   Updated: 2026/07/15 19:31:51 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_ft(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		len++;
	if (num < 0)
		len++;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int	ft_putnbr(long n)
{
	int	len;

	len = len_ft(n);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &(char){n % 10 + '0'}, 1);
	return (len);
}
