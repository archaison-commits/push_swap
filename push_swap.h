/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 20:43:32 by brechied          #+#    #+#             */
/*   Updated: 2026/08/31 20:43:36 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SUCCESS 1
# define ERROR 0

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <stdio.h>

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
}	t_strategy;

typedef struct s_stack
{
	int					index;
	int					value;
	struct s_stack		*next;
}	t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
	t_strategy		strategy;
	double			disorder;
	bool			bench;
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
	int				c_total;
}			t_stacks;

// parse
void		create_stack(t_stack **a, char **numbers);
int			add_number(t_stack **a, char *str);
void		free_numbers(char **numbers);
int			parse_args(int argc, char **argv, t_stacks *stacks,
				t_strategy *strategy);
int			is_valid_number(char *str);
double		compute_disorder(t_stacks *stacks);
void		print_bench(t_strategy strategy, t_stacks *stacks);

//libft
int			is_valid_number(char *str);
int			ft_atoi(const char *nptr);
char		**ft_split(char const *s, char c);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
int			ft_isdigit(int a);
int			is_valid_flag(char *arg);

// Linked list functions
t_stack		*ft_lstnew(int value);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
void		ft_lstdelone(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstclear(t_stack **lst);

// Operator
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks	*stacks);
void		rb(t_stacks	*stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);

// Sorting utils
int			stack_size(t_stack *stack);
int			min_value(t_stack *stack);
void		indexing(t_stacks *stacks);

// Strategy
void		simple_sort(t_stacks *stacks);
void		medium_sort(t_stacks *stacks);
void		complex_sort(t_stacks *stacks);
void		choose_strategy(t_strategy strat, double disorder,
				t_stacks *stacks);
t_strategy	parsing_strategy(char *arg);

// Args
int			valid_arg(int argc, char **argv);
int			check_same_number(t_stack *a);

#endif
