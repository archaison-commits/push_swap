#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
	struct s_stack	*prev;
} t_stack;

double compute_disorder(t_stack *a);

#endif

