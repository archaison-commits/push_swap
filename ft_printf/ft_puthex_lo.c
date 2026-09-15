/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 17:06:11 by brechied          #+#    #+#             */
/*   Updated: 2026/07/21 17:06:13 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_ft(unsigned long num)
{
	int	len;

	len = 0;
	if (num == 0)
		len++;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

int	ft_puthex_lo(unsigned long n)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	if (n > 15)
		ft_puthex_lo(n / 16);
	len = len_ft(n);
	ft_putchar(base[n % 16]);
	return (len);
}
