##
## EPITECH PROJECT, 2024
## B-c-400-REN-4-1-cminilibc-guillaume.blaizot
## File description:
## Makefile
##

VPATH := ./src

vpath %.cpp $(VPATH)

CFLAGS = -Wall -Werror

BUILD_DIR = build

all: $(GRAPHICALS)
	@echo	"Shared library creation done"

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@g++ -c -o $@ $< -fPIC

graphicals:
	@make -C ./libs/NCurses
	@make -C ./libs/SFML
	@make -C ./libs/SDL2
	@echo "Creating shared library NCurses"
	@echo "Creating shared library SFML"
	@echo "Creating shared library SDL2"


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
	@echo "Removed library $(LIB_FOO)"
	@echo "Removed library $(LIB_BAR)"

re: fclean all

.PHONY: all clean fclean re
