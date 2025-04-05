NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
MLX = -lmlx -framework OpenGL -framework AppKit
SRCS = main.c ft_safe_malloc.c exit.c map_parser.c utils.c get_next_line.c get_next_line_utils.c key_hooks.c images.c player.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
