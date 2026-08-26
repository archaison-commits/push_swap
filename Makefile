CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push.c utils.c rotate.c compute_disorder.c \
	push_swap.c swap.c rev_rotate.c	push_swap_utils1.c \
	push_swap_utils2.c
NAME = push_swap

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all
