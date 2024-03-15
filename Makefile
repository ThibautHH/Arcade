##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

EXEC = arcade
VPATH := ./src
CC = g++

vpath %.cpp $(VPATH)

INC_DIR = ./src
INC = -I $(INC_DIR)

SRC := main.cpp

CFLAGS = -Wall -Werror -g -std=c++20 -fPIC -fno-gnu-unique

BUILD_DIR	= build
OBJ			:= $(SRC:%.cpp=$(BUILD_DIR)/%.o)

all: graphicals games core

	@echo	"Shared library creation done"

graphicals:
	@make -C ./lib/Display/NCurses
	@make -C ./lib/Display/SFML
	@make -C ./lib/Display/SDL2
	@echo "Creating shared library NCurses"
	@echo "Creating shared library SFML"
	@echo "Creating shared library SDL2"

core: $(OBJ)
	@echo $(OBJ)
	@$(CC) $^ $(CFLAGS) $(INC) -o $(EXEC)
	@echo "Creating core"

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

games:
	@make -C ./lib/Games/Snake
	@make -C ./lib/Games/Nibbler
	@echo "Creating shared library Snake"
	@echo "Creating shared library Nibbler"

doc:
	@doxygen doc/Doxyfile

clean:
	@ $(RM) *.gcda
	@ $(RM) *.gcno
	@ $(RM) *.gcov
	@ $(RM) vgcore.*
	@rm -rf $(BUILD_DIR)
	@rm -f unit_tests
	@echo "Cleaned up build directory"

fclean: clean
	@rm -f $(EXEC)
	make fclean -C ./lib/Display/NCurses
	make fclean -C ./lib/Display/SFML
	make fclean -C ./lib/Display/SDL2
	make fclean -C ./lib/Games/Snake
	make fclean -C ./lib/Games/Nibbler
	@rm -rf doc/html
	@echo "Removed library NCurses"
	@echo "Removed library SFML"
	@echo "Removed library SDL2"
	@echo "Removed library Snake"
	@echo "Removed library Nibbler"

re: fclean all

.PHONY: all clean fclean re
