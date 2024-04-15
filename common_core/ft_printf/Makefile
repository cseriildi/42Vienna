# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icseri <icseri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 15:39:14 by icseri            #+#    #+#              #
#    Updated: 2024/04/15 12:34:02 by icseri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_strlen.c ft_putnbr_hex.c \
ft_putnbr.c ft_putnbr_unsigned.c ft_putnbr_ptr.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror -g -gdwarf-4

all: ${NAME}

.c.o: 
	clang-14 ${CFLAGS} -c $< -o $@
	
${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean: 
	rm -f ${OBJS}

fclean: 
	rm -f ${OBJS} ${NAME}

re: fclean all

.PHONY: all clean fclean re
