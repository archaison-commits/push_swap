/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 20:41:04 by brechied          #+#    #+#             */
/*   Updated: 2026/07/21 20:41:07 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr)
{
	int					len;
	unsigned long		address;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	address = (unsigned long)ptr;
	len += ft_putstr("0x");
	len += ft_puthex_lo(address);
	return (len);
}
