# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 14:02:21 by acoezard          #+#    #+#              #
#    Updated: 2021/11/02 09:58:12 by acoezard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	fdf

SOURCES			:=	./sources
OBJECTS			:=	./bin
INCLUDES		:=	./includes

LIBFT			:=	./libft

SRCS			:=	fdf.c \
					ft_draw.c \
					ft_window.c \
					ft_hooks.c \
					ft_projection.c \
					ft_parser.c

OBJS			:=	$(addprefix ${OBJECTS}/, $(SRCS:.c=.o))

CC				:=	gcc
CFLAGS			:=	-Wall -Wextra -Werror
CINCLUDES		:=	-I ${INCLUDES}
CDEPENDENCIES	:=	-L ${LIBFT} -lft -lmlx -framework OpenGL -framework AppKit

BLACK			:=	"\033[1;30m"
RED				:=	"\033[1;31m"
GREEN			:=	"\033[1;32m"
CYAN			:=	"\033[1;35m"
BLUE			:=	"\033[1;36m"
WHITE			:=	"\033[1;37m"
EOC				:=	"\033[0;0m"

${OBJECTS}/%.o: ${SOURCES}/%.c
	@mkdir -p $(dir $@)
	@echo "● Compilation de "$(BLUE)"${notdir $<}"$(EOC)"."
	@${CC} ${CFLAGS} -o $@ -c $< ${CINCLUDES}

${NAME}: libft ${OBJS}
	@echo $(GREEN)"● Compilation de ${NAME}..."$(EOC)
	@${CC} ${CFLAGS} -o ${NAME} ${CDEPENDENCIES} ${OBJS}

libft:
	@echo $(GREEN)"● Compilation des sources de la Libft..."$(EOC)
	@make -C ${LIBFT}

all: ${NAME}

clean:
	@echo ${GREEN}"● Supression des fichiers binaires (.o)..."$(EOC)
	@make -C ${LIBFT} clean
	@rm -rf ${OBJECTS}

fclean: clean
	@echo ${GREEN}"● Supression des executables et librairies..."$(EOC)
	@make -C ${LIBFT} fclean
	@rm -f ${NAME}

re: fclean all

.PHONY:	all libft clean fclean re
