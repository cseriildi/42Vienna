# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 15:39:14 by icseri            #+#    #+#              #
#    Updated: 2024/09/08 21:45:03 by cseriildii       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

SRCS = Zombie.cpp newZombie.cpp randomChump.cpp main.cpp

OBJS = ${SRCS:.cpp=.o}

COMP = c++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98 -pedantic

all: ${NAME}

.c.o: 
	${COMP} ${CPPFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${COMP} ${CPPFLAGS} -o ${NAME} ${OBJS}

clean: 
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}
	
re: fclean all

build: all clean

.PHONY: all clean fclean re build
