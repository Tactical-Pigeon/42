# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nahardan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/25 21:39:54 by nahardan          #+#    #+#              #
#    Updated: 2026/10/25 21:41:03 by nahardan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= rush-02
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ft_main.c ft_check.c ft_setnum.c ft_group.c ft_append.c \
		  ft_dict_alloc.c ft_dict_line.c ft_dict_lookup.c \
		  ft_dict_read.c ft_dict_string.c ft_parse_dict.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c ft_rush02.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
