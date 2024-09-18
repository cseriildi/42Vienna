# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 10:47:29 by icseri            #+#    #+#              #
#    Updated: 2024/09/18 15:47:03 by cseriildii       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c \
ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c \
ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c \
ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c \
ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_isascii.c \
ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${SRCS:.c=.o} ${BONUS_SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o: 
	cc ${CFLAGS} -c $< -o $@
	
${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus: .$(NAME:.a=_bonus.a)

.$(NAME:.a=_bonus.a): ${BONUS_OBJS}
	ar rcs .$(NAME:.a=_bonus.a) ${BONUS_OBJS}
	cp .$(NAME:.a=_bonus.a) ${NAME}
	
clean: 
	rm -f ${BONUS_OBJS}

fclean: 
	rm -f ${BONUS_OBJS} ${NAME} .$(NAME:.a=_bonus.a)

re: fclean all

.PHONY: all clean fclean re bonus
