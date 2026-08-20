/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:51:40 by brechied          #+#    #+#             */
/*   Updated: 2026/07/08 15:51:44 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list	*head;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;

	head = NULL;
	node2 = ft_lstnew(ft_strdup("HELP1"));
	node3 = ft_lstnew(ft_strdup("HELP2"));
	node4 = ft_lstnew(ft_strdup("HELP3"));
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);
	ft_lstadd_front(&head, node4);
	printf("content: %s\n", (char *)ft_lstlast(head)->content);
	return (0);
}*/
