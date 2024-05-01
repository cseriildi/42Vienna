# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icseri <icseri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 15:39:14 by icseri            #+#    #+#              #
#    Updated: 2024/05/01 15:49:51 by icseri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

LIBFT_NAME = libft.a

LIBFT_FOLDER = ./libft

SRCS = push_swap.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o: 
	cc ${CFLAGS} -c $< -o $@

makelibft:
	make -C ${LIBFT_FOLDER}

${NAME}: makelibft ${OBJS}
	cp ${LIBFT_FOLDER}/${LIBFT_NAME} ${NAME}

clean: 
	rm -f ${OBJS}
	make -C ${LIBFT_FOLDER} clean

fclean: 
	rm -f ${OBJS} ${NAME}
	make -C ${LIBFT_FOLDER} fclean

re: fclean all

.PHONY: all clean fclean re makelibft
