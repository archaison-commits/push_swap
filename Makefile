CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push.c utils.c rotate.c compute_disorder.c \
	push_swap.c swap.c rev_rotate.c
NAME = push_swap

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

.PHONY: all
