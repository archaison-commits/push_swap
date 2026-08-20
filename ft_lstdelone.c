/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 01:23:33 by brechied          #+#    #+#             */
/*   Updated: 2026/07/09 01:23:36 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_lstdelone(t_stack *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->value);
	free(lst);
}

