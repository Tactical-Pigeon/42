SRCS = main.c validate_file.c find.c read_map.c map_utils.c

OBJS = ${SRCS:.c=.o}

NAME = bsq
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	cc ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.c bsq.h Makefile
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
