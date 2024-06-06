# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 15:39:14 by icseri            #+#    #+#              #
#    Updated: 2024/06/06 17:46:03 by cseriildii       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = 

OBJS = ${SRCS:.c=.o}

COMP = cc

CFLAGS = -Wall -Wextra -Werror -g

all: ${NAME}

.c.o: 
	${COMP} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@${MAKE} -C ./libft --no-print-directory
	@${COMP} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean: 
	@${MAKE} -C ./libft --no-print-directory fclean
	@rm -rf ${OBJS}

fclean: clean
	@rm -rf ${NAME}
	
re: fclean all

.PHONY: all clean fclean re 