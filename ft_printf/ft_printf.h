/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:09:43 by brechied          #+#    #+#             */
/*   Updated: 2026/07/22 17:10:00 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdarg.h>

// int	ft_printf(const char *format, ...) __attribute__((format(printf,1,2)));

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_puthex_lo(unsigned long n);
int	ft_puthex_up(unsigned long n);
int	ft_putnbr_un(unsigned int n);
int	ft_putnbr(long n);
int	ft_putpointer(void *ptr);
int	ft_putstr(char *s);
int	print_porcentage(double n);

#endif
