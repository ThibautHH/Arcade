##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

LIB_NC = arcade_ncurses.so

VPATH := ./src

vpath %.cpp $(VPATH)

SRC_NC := Ncurses.cpp

CFLAGS = -Wall  

BUILD_DIR = build
OBJ_NC := $(SRC_NC:%.cpp=$(BUILD_DIR)/%.o)

all: $(LIB_NC)
	@echo	"Shared library creation done"

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@g++ -c -o $@ $< -fPIC

$(LIB_NC): $(OBJ_NC)
	@ld -shared -lncurses -ldl -o $(LIB_NC) $(OBJ_NC)
	@echo "Creating shared library   $(LIB_NC)"
	@mv $(LIB_NC) ../../

clean:
	@ $(RM) *.gcda
	@ $(RM) *.gcno
	@ $(RM) *.gcov
	@ $(RM) vgcore.*
	@rm -rf $(BUILD_DIR)
	@rm -f unit_tests
	@echo "Cleaned up build directory"

fclean: clean
	@rm -f ../../$(LIB_NC)
	@rm -f $(LIB_BAR)
	@rm -f $(EXEC)
	@echo "Removed library $(LIB_NC)"
	@echo "Removed library $(LIB_BAR)"

re: fclean all

.PHONY: all clean fclean re
