# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 15:39:14 by icseri            #+#    #+#              #
#    Updated: 2024/09/08 15:33:21 by cseriildii       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRCS = PhoneBook.cpp Contact.cpp main.cpp utils.cpp

OBJS = ${SRCS:.cpp=.o}

COMP = c++

CFLAGS = -Wall -Wextra -Werror -g -std=c++98 -pedantic

all: ${NAME}

.c.o: 
	${COMP} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${COMP} ${CFLAGS} -o ${NAME} ${OBJS}

clean: 
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}
	
re: fclean all

build: all clean

.PHONY: all clean fclean re build
