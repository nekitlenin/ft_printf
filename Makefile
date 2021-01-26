# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/23 14:15:16 by pyasuko           #+#    #+#              #
#    Updated: 2021/01/26 17:42:55 by pyasuko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
CFLAGS = -c -Wall -Werror -Wextra
SRC =	ft_char_str.c\
		ft_flags.c\
		ft_hex.c\
		ft_init_flag.c\
		ft_int.c\
		ft_printf.c\
		ft_pointer.c\
		ft_str.c\
		ft_type.c\
		ft_u_int.c\
		ft_utils.c
OBJ = ${SRC:.c=.o}
LIB_DIR = libft
LIB_A = libft/libft.a
INC = ft_printf.h
AR = ar rc
RAN = ranlib
RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}	${INC}
		${MAKE} -C ${LIB_DIR}
		cp ${LIB_A} ${NAME}
		${AR} ${NAME} ${OBJ} ${INC}
		${RAN} ${NAME}

clean:
	${MAKE} clean -C ${LIB_DIR}
	${RM} ${OBJ}

fclean: clean
	${MAKE} fclean -C ${LIB_DIR}
	${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re