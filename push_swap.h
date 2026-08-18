#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
} t_stack;

double	compute_disorder(t_stack *a);
t_stack	*ft_lstnew(int value);
void    ft_lstadd_back(t_stack **lst, t_stack *new);
void    ft_lstadd_front(t_stack **lst, t_stack *new);
void    ft_lstdelone(t_stack *lst, void (*del)(void*));
t_stack *ft_lstlast(t_stack *lst);
t_stack *value_swap(t_stack *dest, t_stack *src);

#endif
