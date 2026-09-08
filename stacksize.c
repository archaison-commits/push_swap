/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacksize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:25:57 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/09/08 21:17:56 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	stsize;

	stsize = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		stsize++;
	}
	return (stsize);
}
