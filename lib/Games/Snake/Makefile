##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

LIB_SNAKE = arcade_snake.so

VPATH := ./src

vpath %.cpp $(VPATH)

SRC_SNAKE := Snake.cpp

CFLAGS = -Wall  

BUILD_DIR = build
OBJ_SNAKE := $(SRC_SNAKE:%.cpp=$(BUILD_DIR)/%.o)

all: $(LIB_SNAKE)
	@echo	"Shared library creation done"

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@g++ -c -o $@ $< -fPIC

$(LIB_SNAKE): $(OBJ_SNAKE)
	@ld -shared -ldl -o $(LIB_SNAKE) $(OBJ_SNAKE)
	@echo "Creating shared library   $(LIB_SNAKE)"

clean:
	@ $(RM) *.gcda
	@ $(RM) *.gcno
	@ $(RM) *.gcov
	@ $(RM) vgcore.*
	@rm -rf $(BUILD_DIR)
	@rm -f unit_tests
	@echo "Cleaned up build directory"

fclean: clean
	@rm -f $(LIB_SNAKE)
	@rm -f $(LIB_BAR)
	@rm -f $(EXEC)
	@echo "Removed library $(LIB_SNAKE)"
	@echo "Removed library $(LIB_BAR)"

re: fclean all

.PHONY: all clean fclean re
