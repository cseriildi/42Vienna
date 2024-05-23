# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 10:47:29 by icseri            #+#    #+#              #
#    Updated: 2024/05/23 22:21:17 by cseriildii       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c \
ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c \
ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c \
ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c \
ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_isascii.c \
ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr_hex.c \
ft_putnbr.c ft_putnbr_unsigned.c ft_putnbr_ptr.c \
get_next_line.c get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o: 
	cc ${CFLAGS} -c $< -o $@
	
${NAME}: ${OBJS}
	ar -rc ${NAME} ${OBJS}
	ranlib $(NAME)

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
