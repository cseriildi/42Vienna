# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icseri <icseri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 15:39:14 by icseri            #+#    #+#              #
#    Updated: 2024/05/03 14:57:03 by icseri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_FOLDER = ./libft

SRCS = push_swap.c operations.c sorting.c list.c

LIBFT_SRCS = ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c \
ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c \
ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c \
ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c \
ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_isascii.c \
ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c ft_strtrim.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = ${SRCS:.c=.o}

LIBFT_OBJS = ${addprefix ${LIBFT_FOLDER}/,${LIBFT_SRCS:.c=.o}}

COMP = cc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o: 
	${COMP} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} ${LIBFT_OBJS}
	${COMP} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT_OBJS}

clean: 
	rm -f ${OBJS} ${LIBFT_OBJS}

fclean: 
	@$(MAKE) clean
	rm -f ${NAME}
	
re: fclean all

.PHONY: all clean fclean re 
