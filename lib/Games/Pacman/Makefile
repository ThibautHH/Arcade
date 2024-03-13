##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

LIB_PACMAN = libpacman.so

VPATH := ./src

vpath %.cpp $(VPATH)

SRC_PACMAN := Pacman.cpp

CFLAGS = -Wall -Werror

BUILD_DIR = build
OBJ_PACMAN := $(SRC_PACMAN:%.cpp=$(BUILD_DIR)/%.o)

all: $(LIB_PACMAN)
	@echo	"Shared library creation done"

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@g++ -c -o $@ $< -fPIC

$(LIB_PACMAN): $(OBJ_PACMAN)
	@ld -shared -ldl -o $(LIB_PACMAN) $(OBJ_PACMAN)
	@echo "Creating shared library   $(LIB_PACMAN)"

clean:
	@ $(RM) *.gcda
	@ $(RM) *.gcno
	@ $(RM) *.gcov
	@ $(RM) vgcore.*
	@rm -rf $(BUILD_DIR)
	@rm -f unit_tests
	@echo "Cleaned up build directory"

fclean: clean
	@rm -f $(LIB_PACMAN)
	@rm -f $(LIB_BAR)
	@rm -f $(EXEC)
	@echo "Removed library $(LIB_PACMAN)"
	@echo "Removed library $(LIB_BAR)"

re: fclean all

.PHONY: all clean fclean re
