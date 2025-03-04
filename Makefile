SOURCES = server.c client.c 
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: server.o ft_printf 
	$(CC) -o $@ $< -Lft_printf -lftprintf

client: client.o
	$(CC) -o $@ $< -Lft_printf -lftprintf

%.o: %.c
	$(CC) -c $(CFLAGS) $?

ft_printf:
	make -C ft_printf

clean:
	rm -f $(OBJECTS)
	make -C ft_printf clean
	
fclean: clean
	rm -f server client 
	rm -f ft_printf/ft_printf.a

re: fclean all

.PHONY: all bonus clean fclean re
