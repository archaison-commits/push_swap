NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c complex.c compute_disorder.c libft_utils1.c \
	 libft_utils2.c medium.c push.c rev_rotate.c print_bench.c \
	rotate.c simple.c sorting_utils.c swap.c utils.c valid_arg.c \
	parcing_utils.c strategy.c \
	ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_puthex_lo.c ft_printf/ft_puthex_up.c \
	ft_printf/ft_putnbr_un.c ft_printf/ft_putnbr.c ft_printf/ft_putpointer.c ft_printf/ft_putstr.c \
	ft_printf/print_porcentage.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
