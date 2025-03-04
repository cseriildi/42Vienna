CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98 -pedantic

OBJ_DIR = obj
$(shell mkdir -p $(OBJ_DIR))

OBJS = $(SRCS:.cpp=.o)

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(OBJS)))

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ_FILES)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME) $(ARGS)

deps: $(SRCS)
	$(CXX) $(CXXFLAGS) -M $(SRCS) > Makefile.deps

-include Makefile.deps

val: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS)

san: $(NAME)
	$(CXX) $(CXXFLAGS) -fsanitize=address,undefined,bounds -o $(NAME) $(SRCS)
	./$(NAME) $(ARGS)

.PHONY: all clean fclean re run val san
