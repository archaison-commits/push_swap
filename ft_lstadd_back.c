/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 17:44:43 by brechied          #+#    #+#             */
/*   Updated: 2026/07/08 19:46:04 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*lst1;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst1 = ft_lstlast(*lst);
	lst1->next = new;
}
/*
int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	head = NULL;
	node1 = ft_lstnew(ft_strdup("HELP1"));
	node2 = ft_lstnew(ft_strdup("HELP2"));
	node3 = ft_lstnew(ft_strdup("HELP3"));
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);
	ft_lstadd_back(&head, node1);
	while (head)
	{
		printf("content: %s\n", (char *)head->content);
		head = head->next;
	}
	return (0);
}*/
