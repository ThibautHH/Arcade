##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

LIB_SDL = arcade_sdl2.so

VPATH := ./src

vpath %.cpp $(VPATH)

SRC_SDL := Sdl.cpp

CFLAGS = -Wall

BUILD_DIR = build
OBJ_SDL := $(SRC_SDL:%.cpp=$(BUILD_DIR)/%.o)

all: $(LIB_SDL)
	@ln -sf Display/SDL2/$(LIB_SDL) ../../$(LIB_SDL)
	@echo	"Shared library creation done"

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@g++ -c -o $@ $< -fPIC

$(LIB_SDL): $(OBJ_SDL)
	@ld -shared -ldl -o $(LIB_SDL) $(OBJ_SDL) -lSDL2 -lSDL2_image -lSDL2_ttf
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
	@rm -f ../../$(LIB_SDL)
	@rm -f $(LIB_BAR)
	@rm -f $(EXEC)
	@echo "Removed library $(LIB_SDL)"

re: fclean all

.PHONY: all clean fclean re
