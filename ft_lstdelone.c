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
/*
void delete_content(void *content)
{
    free(content);
}

int main(void)
{
    printf("--- Creating target node ---\n");
    // Allocate a node containing a dynamically allocated string
    t_list *target_node = ft_lstnew(ft_strdup("Delete Me!"));

    // Check that memory exists before deletion
    printf("Node address: %p\n", (void *)target_node);
    printf("Content string: %s\n", (char *)target_node->content);

    printf("\n--- Executing ft_lstdelone ---\n");
    // Pass the node and the address of the delete function
    ft_lstdelone(target_node, &delete_content);

    printf("Node successfully deleted and memory freed.\n");

    // Visualizing explicit safety guards
    printf("\n--- Test Edge Case: Passing NULL ---\n");
    ft_lstdelone(NULL, &delete_content); // Should safely return without crashing

    return (0);
}

int main(void)
{
	signal(SIGSEGV, sigsegv); (void)iTest;
	title("ft_lstdelone\t: ");

	t_list * l =  ft_lstnew(malloc(1));
	ft_lstdelone(l, free); l = 0;
	showLeaks();
	write(1, "\n", 1);
	return (0);
}
*/
