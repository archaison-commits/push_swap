/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_porcentage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:31:45 by brechied          #+#    #+#             */
/*   Updated: 2026/07/15 19:31:51 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_porcentage(double n)
{
	int		len;
	int		integer;
	int		decimal;

	n *= 100;
	integer = (int)n;
	decimal = (int)((n - integer) * 100);
	len = ft_putnbr(integer);
	write(1, ".", 1);
	len++;
	if (decimal < 10)
	{
		write(1, "0", 1);
		len++;
	}
	len += ft_putnbr(decimal);
	write(1, "%", 1);
	len++;
	return (len);
}
