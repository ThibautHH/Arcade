##
## EPITECH PROJECT, 2024
## B-c-400-REN-4-1-cminilibc-guillaume.blaizot
## File description:
## Makefile
##

LIB_SFML = libsfml.so

VPATH := ./src

vpath %.cpp $(VPATH)

SRC_SFML := Sfml.cpp

CFLAGS = -Wall -Werror

BUILD_DIR = build
OBJ_SFML := $(SRC_SFML:%.cpp=$(BUILD_DIR)/%.o)

all: $(LIB_SFML)
	@echo	"Shared library creation done"

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@g++ -c -o $@ $< -fPIC

$(LIB_SFML): $(OBJ_SFML)
	@ld -shared -ldl -o $(LIB_SFML) $(OBJ_SFML)
	@echo "Creating shared library   $(LIB_SFML)"

clean:
	@ $(RM) *.gcda
	@ $(RM) *.gcno
	@ $(RM) *.gcov
	@ $(RM) vgcore.*
	@rm -rf $(BUILD_DIR)
	@rm -f unit_tests
	@echo "Cleaned up build directory"

fclean: clean
	@rm -f $(LIB_SFML)
	@rm -f $(LIB_BAR)
	@rm -f $(EXEC)
	@echo "Removed library $(LIB_SFML)"
	@echo "Removed library $(LIB_BAR)"

re: fclean all

.PHONY: all clean fclean re
