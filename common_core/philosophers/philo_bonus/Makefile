# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icseri <icseri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 13:35:49 by icseri            #+#    #+#              #
#    Updated: 2024/08/29 16:05:23 by icseri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo_bonus

SRCS = main.c init.c libft.c cleanup.c time.c simulation.c utils.c events.c

OBJS = ${SRCS:.c=.o}

COMP = cc

CFLAGS = -Wall -Wextra -Werror -g -pthread #-fsanitize=thread,undefined

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
