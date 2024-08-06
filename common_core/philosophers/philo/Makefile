# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 13:35:49 by icseri            #+#    #+#              #
#    Updated: 2024/08/06 17:45:26 by cseriildii       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

SRCS = main.c init.c utils.c events.c routine.c time.c cleanup.c libft.c

OBJS = ${SRCS:.c=.o}

COMP = cc

CFLAGS = -Wall -Wextra -Werror -g -pthread

all: ${NAME}

.c.o: 
	${COMP} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${COMP} ${CFLAGS} ${OBJS} -o ${NAME}

clean: 
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}
	
re: fclean all

.PHONY: all clean fclean re
