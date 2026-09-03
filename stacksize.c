/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacksize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:25:57 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/03 18:06:41 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacksize(t_stack *stack)
{
	int stsize;

	stsize = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		stsize++;
	}
	return (stsize);
}
