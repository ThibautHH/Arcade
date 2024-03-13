##
## EPITECH PROJECT, 2024
## B-c-400-REN-4-1-cminilibc-guillaume.blaizot
## File description:
## Makefile
##

LIB_SDL = libsdl.so

VPATH := ./src

vpath %.cpp $(VPATH)

SRC_SDL := Sdl.cpp

CFLAGS = -Wall -Werror

BUILD_DIR = build
OBJ_SDL := $(SRC_SDL:%.cpp=$(BUILD_DIR)/%.o)

all: $(LIB_SDL)
	@echo	"Shared library creation done"

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@g++ -c -o $@ $< -fPIC

$(LIB_SDL): $(OBJ_SDL)
	@ld -shared -ldl -o $(LIB_SDL) $(OBJ_SDL)
	@echo "Creating shared library   $(LIB_SDL)"

clean:
	@ $(RM) *.gcda
	@ $(RM) *.gcno
	@ $(RM) *.gcov
	@ $(RM) vgcore.*
	@rm -rf $(BUILD_DIR)
	@rm -f unit_tests
	@echo "Cleaned up build directory"

fclean: clean
	@rm -f $(LIB_SDL)
	@rm -f $(LIB_BAR)
	@rm -f $(EXEC)
	@echo "Removed library $(LIB_SDL)"
	@echo "Removed library $(LIB_BAR)"

re: fclean all

.PHONY: all clean fclean re
