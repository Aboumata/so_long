CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iminilibx-linux

SRCS		= map_parsing.c \
			  map_validating.c \
			  game.c \
			  so_long_utils.c \
			  free_memory.c \
			  get_next_line/get_next_line.c \
			  get_next_line/get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

NAME		= so_long

MLX_DIR		= minilibx-linux
MLX_LIB		= -L$(MLX_DIR) -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_LIB)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
