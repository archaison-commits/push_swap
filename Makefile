NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c complex.c compute_disorder.c ft_split.c \
	ft_strncmp.c libft_utils.c medium.c push.c rev_rotate.c \
	rotate.c simple.c sorting_utils.c swap.c utils.c valid_arg.c


all:
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

.PHONY: all
