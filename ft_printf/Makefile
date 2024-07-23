NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_ptr.c ft_printf_x.c ft_printf_u.c ft_printf_di.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o:%.c libft.h Makefile
	$(CC) $(CFLAGS) $(INC) $< -c -o $@

bonus: $(BONUS_OBJS)
	ar -rcs $(NAME) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all



.PHONY: all clean fclean re bonus