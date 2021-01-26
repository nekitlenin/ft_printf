# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 21:06:42 by pyasuko           #+#    #+#              #
#    Updated: 2021/01/25 21:28:29 by pyasuko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC =	ft_strlen.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_tolower.c\
		ft_strdup.c\
		ft_itoa.c\
		ft_itoa_base.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putstr_len.c
OBJ = ${SRC:.c=.o}
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -I . -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}:	${OBJ}
			ar rc ${NAME} ${OBJ}
			ranlib ${NAME}

clean:
			rm -rf ${OBJ}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all
