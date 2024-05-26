# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 15:39:14 by icseri            #+#    #+#              #
#    Updated: 2024/05/26 22:21:33 by cseriildii       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c utils.c parsing.c

BONUS_SRCS = pipex_bonus.c utils.c parsing.c

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

COMP = cc

CFLAGS = -Wall -Wextra -Werror -g

all: ${NAME} 

.c.o: 
	${COMP} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${MAKE} -C ./libft --no-print-directory
	${COMP} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

bonus: ${BONUS_OBJS}
	${MAKE} -C ./libft --no-print-directory
	${COMP} ${CFLAGS} ${BONUS_OBJS} ./libft/libft.a -o ${NAME}

clean: 
	${MAKE} -C ./libft --no-print-directory fclean
	rm -rf ${OBJS} ${BONUS_OBJS}

fclean: clean
	rm -rf ${NAME}
	
re: fclean all

.PHONY: all clean fclean re bonus
