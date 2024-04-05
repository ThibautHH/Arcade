##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

LIB_SFML = arcade_sfml.so

VPATH := ./src

vpath %.cpp $(VPATH)

SRC_SFML := Sfml.cpp

CFLAGS = -Wall -Wextra -std=c++20
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

BUILD_DIR = build
OBJ_SFML := $(SRC_SFML:%.cpp=$(BUILD_DIR)/%.o)

all: $(LIB_SFML)
	@ln -sf Display/SFML/$(LIB_SFML) ../../$(LIB_SFML)
	@echo	"Shared library creation done"

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@g++ -c -o $@ $< -fPIC $(CFLAGS)

$(LIB_SFML): $(OBJ_SFML)
	@gcc -shared -ldl -o $(LIB_SFML) $(OBJ_SFML) $(SFML_LIBS)
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
	@rm -f ../../$(LIB_SFML)
	@rm -f $(LIB_BAR)
	@rm -f $(EXEC)
	@echo "Removed library $(LIB_SFML)"

re: fclean all

.PHONY: all clean fclean re
