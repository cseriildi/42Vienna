# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icseri <icseri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 15:39:14 by icseri            #+#    #+#              #
#    Updated: 2024/05/17 10:17:19 by icseri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

SRCS = main.c list.c utils.c utils2.c input_check_and_parsing.c operations.c sort_utils.c sort_part1.c sort_part2.c

LIBFT_SRCS = ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c \
ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c \
ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c \
ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c \
ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_isascii.c \
ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c ft_strtrim.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

FT_PRINTF_SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr_hex.c \
ft_putnbr.c ft_putnbr_unsigned.c ft_putnbr_ptr.c

GNL_SRCS = get_next_line.c get_next_line_utils.c

BONUS_SRCS = checker_bonus.c list.c utils.c utils2.c input_check_and_parsing.c operations.c

OBJS = ${SRCS:.c=.o}

LIBFT_OBJS = ${addprefix ./libft/,${LIBFT_SRCS:.c=.o}}

FT_PRINTF_OBJS = ${addprefix ./ft_printf/,${FT_PRINTF_SRCS:.c=.o}}

GNL_OBJS = ${addprefix ./gnl/,${GNL_SRCS:.c=.o}}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

COMP = cc

CFLAGS = -Wall -Wextra -Werror -g

all: ${NAME}

.c.o: 
	${COMP} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} ${LIBFT_OBJS} ${FT_PRINTF_OBJS}
	${COMP} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT_OBJS} ${FT_PRINTF_OBJS}

bonus: ${BONUS_OBJS} ${LIBFT_OBJS} ${FT_PRINTF_OBJS} ${GNL_OBJS}
	${COMP} ${CFLAGS} -o ${BONUS_NAME} ${BONUS_OBJS} ${GNL_OBJS} ${LIBFT_OBJS} ${FT_PRINTF_OBJS}

clean: 
	rm -f ${OBJS} ${BONUS_OBJS} ${LIBFT_OBJS} ${FT_PRINTF_OBJS} ${GNL_OBJS}

fclean: 
	@$(MAKE) clean
	rm -f ${NAME} ${BONUS_NAME}
	
re: fclean all

.PHONY: all clean fclean re bonus
