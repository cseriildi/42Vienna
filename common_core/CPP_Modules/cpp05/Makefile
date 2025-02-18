CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98 -pedantic #-fsanitize=address,undefined,bounds

OBJS = ${SRCS:.cpp=.o}

all: $(NAME)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
