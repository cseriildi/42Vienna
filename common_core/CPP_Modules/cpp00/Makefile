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
