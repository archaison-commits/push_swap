/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brechied <brechied@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:12:01 by brechied          #+#    #+#             */
/*   Updated: 2026/08/18 18:12:05 by brechied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	UNDEFINE,
}	t_strategy;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_stacks
{
	struct t_stack	*a;
	struct t_stack	*b;
	t_strategy		strategy;
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
}			t_stacks;

double	compute_disorder(t_stack *a);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif
