# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icseri <icseri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 15:39:14 by icseri            #+#    #+#              #
#    Updated: 2024/05/31 14:00:48 by icseri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

BONUS_NAME = pipex_bonus

SRCS = pipex.c utils.c parsing.c utils2.c

BONUS_SRCS = pipex_bonus.c utils.c utils2.c parsing.c utils_bonus.c

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

COMP = cc

CFLAGS = -Wall -Wextra -Werror -g

all: ${NAME}

.c.o: 
	${COMP} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@${MAKE} -C ./libft --no-print-directory
	@${COMP} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

bonus: ${BONUS_OBJS}
	@${MAKE} -C ./libft --no-print-directory
	@${COMP} ${CFLAGS} ${BONUS_OBJS} ./libft/libft.a -o ${BONUS_NAME}

clean: 
	@${MAKE} -C ./libft --no-print-directory fclean
	@rm -rf ${OBJS} ${BONUS_OBJS}

fclean: clean
	@rm -rf ${NAME} ${BONUS_NAME}
	
re: fclean all

.PHONY: all clean fclean re bonus
