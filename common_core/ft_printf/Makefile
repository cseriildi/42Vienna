# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icseri <icseri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 15:39:14 by icseri            #+#    #+#              #
#    Updated: 2024/04/12 19:13:09 by icseri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_putnbr_base.c ft_putchar.c ft_putstr.c ft_strlen.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o: 
	cc ${CFLAGS} -c $< -o $@
	
${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean: 
	rm -f ${OBJS}

fclean: 
	rm -f ${OBJS} ${NAME}

re: fclean all

.PHONY: all clean fclean re
