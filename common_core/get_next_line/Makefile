# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icseri <icseri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 15:39:14 by icseri            #+#    #+#              #
#    Updated: 2024/04/16 18:48:39 by icseri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c

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
