CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98 -pedantic
SAN_FLAGS = -fsanitize=address,undefined,bounds
VAL_FLAGS = --leak-check=full --show-leak-kinds=all

OBJ_DIR = obj
DEPS_DIR = $(OBJ_DIR)/.deps

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))
DEPS = $(addprefix $(DEPS_DIR)/, $(notdir $(SRCS:.cpp=.d)))

.PHONY: all
all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(DEPS_DIR):
	mkdir -p $(DEPS_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR) $(DEPS_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -MF $(DEPS_DIR)/$(notdir $(<:.cpp=.d)) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

-include $(DEPS)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all

.PHONY: run
run: $(NAME)
	./$(NAME) $(ARGS)

.PHONY: val
val: re
	valgrind $(VAL_FLAGS) ./$(NAME) $(ARGS)

.PHONY: san
san: CXXFLAGS += $(SAN_FLAGS)
san: run
