NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Iincludes -Ilibft -Ilibft/ft_printf

LIBFT	= libft/libft.a

SRCS	= main.c \
		srcs/stack/node_operations.c \
		srcs/stack/node_operations_utils.c \
		srcs/operations/push.c \
		srcs/operations/swap.c \
		srcs/operations/rotate.c \
		srcs/operations/reverse_rotate.c \
		srcs/algorithms/simple/insertion_sort.c \
		srcs/algorithms/medium/chunk_sort.c \
		srcs/algorithms/medium/chunk_sort_utils.c \
		srcs/algorithms/complex/radix_sort.c \
		srcs/algorithms/adaptive/adaptive_sort.c \
		srcs/benchmark/disorder.c \
		srcs/benchmark/benchmark.c \
		srcs/parsing/parsing.c \
		srcs/parsing/parsing_utils.c \
		srcs/parsing/validation.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c includes/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re