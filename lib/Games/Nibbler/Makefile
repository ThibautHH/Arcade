##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

LIB_NIBBLER = arcade_nibbler.so

VPATH := ./src

vpath %.cpp $(VPATH)

SRC_NIBBLER := Nibbler.cpp

CFLAGS = -Wall

BUILD_DIR = build
OBJ_NIBBLER := $(SRC_NIBBLER:%.cpp=$(BUILD_DIR)/%.o)

all: $(LIB_NIBBLER)
	@echo	"Shared library creation done"

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@g++ -c -o $@ $< -fPIC

$(LIB_NIBBLER): $(OBJ_NIBBLER)
	@ld -shared -ldl -o $(LIB_NIBBLER) $(OBJ_NIBBLER)
	@echo "Creating shared library   $(LIB_NIBBLER)"
	@mv $(LIB_NIBBLER) ../../

clean:
	@ $(RM) *.gcda
	@ $(RM) *.gcno
	@ $(RM) *.gcov
	@ $(RM) vgcore.*
	@rm -rf $(BUILD_DIR)
	@rm -f unit_tests
	@echo "Cleaned up build directory"

fclean: clean
	@rm -f ../../$(LIB_NIBBLER)
	@rm -f $(LIB_BAR)
	@rm -f $(EXEC)
	@echo "Removed library $(LIB_NIBBLER)"
	@echo "Removed library $(LIB_BAR)"

re: fclean all

.PHONY: all clean fclean re
