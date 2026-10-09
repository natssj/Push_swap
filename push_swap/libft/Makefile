NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I. -I./ft_printf
AR			= ar rcs
RM			= rm -f

LIBFT_SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_strlen.c \
			ft_bzero.c ft_isprint.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
			ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
			ft_atoi.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c get_next_line.c

PRINTF_SRCS	= ft_printf/ft_printf.c ft_printf/ft_print_numbers.c \
			ft_printf/ft_print_words.c ft_printf/utils.c

OBJS		= $(LIBFT_SRCS:.c=.o) $(PRINTF_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re