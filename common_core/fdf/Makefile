# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icseri <icseri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 15:39:14 by icseri            #+#    #+#              #
#    Updated: 2024/06/18 12:03:43 by icseri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = fdf.c parsing.c utils.c events.c iso_proj.c drawing.c ft_atoi_base.c

OBJS = ${SRCS:.c=.o}

COMP = cc

CFLAGS = -Wall -Wextra -Werror -g 

MINILIBX_FLAGS = -lXext -lX11 -lm -lz -lmlx

all: ${NAME}

.c.o: 
	${COMP} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@${MAKE} -C ./libft --no-print-directory
	@${COMP} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME} ${MINILIBX_FLAGS}

clean: 
	@${MAKE} -C ./libft --no-print-directory fclean
	@rm -rf ${OBJS}

fclean: clean
	@rm -rf ${NAME}
	
re: fclean all

.PHONY: all clean fclean re 
