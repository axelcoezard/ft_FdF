# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 14:55:49 by acoezard          #+#    #+#              #
#    Updated: 2021/10/24 15:49:23 by acoezard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF

SOURCES = ./sources

SRCS = main.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}: ${OBJS}
	$(CC) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
