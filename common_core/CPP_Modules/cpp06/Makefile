ifdef NAME

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
	@mkdir -p $(OBJ_DIR)

$(DEPS_DIR):
	@mkdir -p $(DEPS_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR) $(DEPS_DIR)
	@printf "$(ITALIC)"
	$(CXX) $(CXXFLAGS) -MMD -MP -MF $(DEPS_DIR)/$(notdir $(<:.cpp=.d)) -c $< -o $@
	@printf "$(RESET)"

$(NAME): $(OBJS)
	@printf "$(ITALIC)"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Executable: ./$(NAME)$(RESET)"

-include $(DEPS)

.PHONY: clean
clean:
	@printf "$(ITALIC)"
	rm -rf $(OBJ_DIR)
	@printf "$(RESET)"

.PHONY: fclean
fclean: clean
	@printf "$(ITALIC)"
	rm -rf $(NAME)
	@printf "$(RESET)"

.PHONY: re
re: fclean all

.PHONY: run
run: all
	@echo
	@./$(NAME) $(ARGS)

.PHONY: val
val: re
	@echo
	valgrind $(VAL_FLAGS) ./$(NAME) $(ARGS)

.PHONY: san
san: CXXFLAGS += $(SAN_FLAGS)
san: run

.PHONY: help
help:
	$(call print_help)

$(DEPS):
	@true

.DEFAULT:
	$(call print_help)

else

.PHONY: all
all:
	$(call run_make_in_subdirs, all)

.PHONY: help
help:
	$(call print_help)

.DEFAULT:
	$(call run_make_in_subdirs, $@)

endif

ITALIC=\033[3m
BOLD=\033[1m
RESET=\033[0m
GREEN=\033[32m
BLUE=\033[34m

define print_help
	@echo "Available Makefile rules:"
	@echo "  all        - Build the project"
	@echo "  clean      - Remove object files and dependencies"
	@echo "  fclean     - Remove object files, dependencies and the executable"
	@echo "  re         - Clean and rebuild the project"
	@echo "  run [ARGS] - Run the executable"
	@echo "  val [ARGS] - Run the executable with valgrind"
	@echo "  san [ARGS] - Run the executable with sanitizer"
	@echo "  help       - Show this help message"
endef

define run_make_in_subdirs
	@for dir in $$(find . -mindepth 2 -type f -name 'Makefile' -exec dirname {} \; | sort -u); do \
		echo "$(BOLD)$(BLUE)Running make$(1) in $$dir$(RESET)"; \
		$(MAKE) --no-print-directory -C $$dir $(1); \
	done
endef
