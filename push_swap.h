#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_stack
{
	int				index;
    int             value;
    struct s_stack  *next;
} t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
	int				c_sa;
	int				c_sb;
	int				c_ss;
	int				c_pa;
	int				c_pb;
	int				c_ra;
	int				c_rb;
	int				c_rr;
	int				c_rra;
	int				c_rrb;
	int				c_rrr;
}			t_stacks;

double	compute_disorder(t_stack *a);
t_stack	*ft_lstnew(int value);
void    ft_lstadd_back(t_stack **lst, t_stack *new);
void    ft_lstadd_front(t_stack **lst, t_stack *new);
void    ft_lstdelone(t_stack *lst, void (*del)(void*));
t_stack *ft_lstlast(t_stack *lst);
void value_swap(t_stacks *stacks);

#endif
