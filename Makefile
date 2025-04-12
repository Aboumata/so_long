CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c \
			  map_parsing.c \
			  map_validation.c \
			  game.c \
			  so_long_utils.c \
			  get_next_line/get_next_line.c \
			  get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
