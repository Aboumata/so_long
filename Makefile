CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = parsing_game.c so_long_utils.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re : fclean all

.PHONY: all clean fclean re
