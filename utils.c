/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniwinsk <mniwinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:05:29 by mniwinsk          #+#    #+#             */
/*   Updated: 2026/08/19 14:30:42 by mniwinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*t_stack	*ft_lstnew(int value)
{
	t_list	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->value = value;
	head->next = NULL;
	return (head);
}
*/
t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
/*
void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*very_good_very_back;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	very_good_very_back = ft_lstlast(*lst);
	very_good_very_back->next = new;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstdelone(t_stack *lst, void (*del)(void*))
{
	if (!del || !lst)
		return ;
	del(lst->value);
	free(lst);
}*/
