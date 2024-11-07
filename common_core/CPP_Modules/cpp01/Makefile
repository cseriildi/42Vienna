# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 12:35:56 by cseriildii        #+#    #+#              #
#    Updated: 2024/10/30 12:36:04 by cseriildii       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMP = c++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98 -pedantic

OBJS = ${SRCS:.cpp=.o}

all: $(NAME)

.cpp.o:
	$(COMP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(COMP) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
