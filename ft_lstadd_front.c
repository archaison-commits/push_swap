/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 15:01:22 by brechied          #+#    #+#             */
/*   Updated: 2026/07/07 15:01:26 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*head;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	*tmp;

	head = NULL;
	node2 = ft_lstnew(ft_strdup("HELP1"));
	node3 = ft_lstnew(ft_strdup("HELP2"));
	node4 = ft_lstnew(ft_strdup("HELP3"));
	ft_lstadd_front(&head, node4);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);
	tmp = head;
	while (head)
	{
		printf("content: %s\n", (char *)head->content);
		head = head->next;
	}
	while (head)
	{
		printf("content: %s\n", (char *)head->content);
		head = head->next;
	}
	return (0);
}*/
