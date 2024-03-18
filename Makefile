##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

.SECONDEXPANSION:
NAME					:=	arcade
$(NAME)_LINK			:=	1
ifdef $(NAME)_LINK
$(NAME)_TARGET			:=	$(NAME)
else
$(NAME)_TARGET			:=	$(NAME:%=lib%.a)
endif
$(NAME)_DISPLAY			:=	Arcade
$(NAME)_TESTS			:=	$(NAME)_tests

SRC_DIR					:=	src/
BUILD_DIR				:=	obj/
TESTS_DIR				:=	tests/

$(NAME)_MAIN_SRC		:=	$(SRC_DIR)Main.cpp
$(NAME)_SRCS			:=	$(addprefix $(SRC_DIR), $(addsuffix .cpp,	\
								Termination								\
								$(addprefix Core/,						\
									DynamicLibrary ModuleLibrary		\
									Processor)							\
							))
$($(NAME)_TESTS)_SRCS	:=	$(shell find $(TESTS_DIR) -type f			\
							-name '*.cpp' ! -name ".*" 2>/dev/null)

IGNORE_FILE				:=	.gitignore
IGNORED_FILES			:=	compile_commands.json .vscode .cache doc/html
ifndef $(NAME)_LINK
IGNORED_FILES			+=  $($(NAME)_MAIN_SRC)
endif
CODING_STYLE_LOG		:=	coding-style-reports.log

$(NAME)_MAIN_OBJ		:=										\
	$($(NAME)_MAIN_SRC:$(SRC_DIR)%.cpp=$(BUILD_DIR)%.o)
$(NAME)_OBJS			:=										\
	$($(NAME)_SRCS:$(SRC_DIR)%.cpp=$(BUILD_DIR)%.o)
$($(NAME)_TESTS)_OBJS	:=										\
	$($($(NAME)_TESTS)_SRCS:$(SRC_DIR)%.cpp=$(BUILD_DIR)%.o)

$(NAME)_MAIN_DEP		:=	$($(NAME)_MAIN_OBJ:.o=.d)
$(NAME)_DEPS			:=	$($(NAME)_OBJS:.o=.d)
$($(NAME)_TESTS)_DEPS	:=	$($($(NAME)_TESTS)_OBJS:.o=.d)

LIBS					:=
ifndef $(NAME)_LINK
LIB_DIRS				+=	$(dir $($(NAME)_TARGET))
endif
HDR						=	$(findstring $(SRC_DIR)$*.hpp,$^)
PCH						=	$(HDR:$(SRC_DIR)%.hpp=$(BUILD_DIR)%.hpp.gch)
RM						:=	rm -r
AR						:=	ar
ARFLAGS					:=	rcs
CXX						:=	g++
PCHFLAGS				=	$(patsubst %,-iquote %,$(dir $(PCH)))			\
							$(patsubst %,-include %,$(notdir $(HDR)))
CXXFLAGS				=	$(PCHFLAGS) $(PROJECT_INCLUDE_DIRS:%=-iquote %)	\
							-std=c++20										\
							-W -Wall -Wextra -Wduplicated-cond				\
							-Wduplicated-branches -Wlogical-op				\
							-Wnull-dereference -Wdouble-promotion -Wshadow	\
							-Wformat=2 -Wpedantic							\
							-fno-gnu-unique
LDLIBS					=	$(LIBS:%=-l%)
LDFLAGS					=	$(LIB_DIRS:%=-L%)

all:						$(IGNORE_FILE) games graphicals $($(NAME)_TARGET)
	@:

debug:						CXXFLAGS += -g
debug:						all

games:
	@-echo "Creating shared library Snake..." >&2
	@make -C ./lib/Games/Snake
	@-echo "Creating shared library Nibbler..." >&2
	@make -C ./lib/Games/Nibbler

graphicals:
	@-echo "Creating shared library NCurses..." >&2
	@make -C ./lib/Display/NCurses
	@-echo "Creating shared library SFML..." >&2
	@make -C ./lib/Display/SFML
	@-echo "Creating shared library SDL2..." >&2
	@make -C ./lib/Display/SDL2

include $(IGNORE_FILE).mk

$($(NAME)_TARGET):			$($(NAME)_OBJS)
ifdef $(NAME)_LINK
$($(NAME)_TARGET):			$($(NAME)_MAIN_OBJ)
	@-echo 'Linking $@ binary...'
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS) $(LDFLAGS)
else
$($(NAME)_TARGET):
	@-echo 'Archiving $(@:lib%.a=%) objects into $@...'
	@$(AR) $(ARFLAGS) $@ $^
endif

ifndef $(NAME)_LINK
main_debug:					CXXFLAGS += -g
main_debug:					main
	@:

main: 						LIBS += $(NAME)
main:						$($(NAME)_MAIN_OBJ) $($(NAME)_TARGET)	\
							$(IGNORE_FILE)
	@-echo 'Linking $(NAME) binary...'
	@$(CXX) $(CXXFLAGS) -o $(NAME) $< $(LDLIBS) $(LDFLAGS)
endif

-include $($(NAME)_MAIN_DEP) $($(NAME)_DEPS) $($($(NAME)_TESTS)_DEPS)

$(BUILD_DIR)%.d:			$(SRC_DIR)%.cpp
	@-echo 'Generating dependencies for $<...' >&2
	@mkdir -p $(dir $@)
	@$(CXX) $< -MM -MF $@ -MT $(@:.d=.o) $(CXXFLAGS)

$(BUILD_DIR)%.hpp.gch:		CXXFLAGS := $(filter-out $(PCHFLAGS),$(CXXFLAGS))
$(BUILD_DIR)%.hpp.gch:		$(SRC_DIR)%.hpp
	@-echo 'Precompiling $<...' >&2
	@mkdir -p $(dir $@)
	@$(CXX) -c $(CXXFLAGS) $< -o $@

$(BUILD_DIR)%.o:			$(SRC_DIR)%.cpp $$(PCH)
	@-echo 'Compiling $<...' >&2
	@mkdir -p $(dir $@)
	@$(CXX) -c $(CXXFLAGS) $< -o $@

docs:						$(IGNORE_FILE)
	@-echo 'Generating documentation...' >&2
	@doxygen doc/Doxyfile

coding-style:				fclean
	@-echo 'Checking coding style...' >&2

clean:
	@-echo 'Deleting build directory...' >&2
	@$(RM) -f $(BUILD_DIR)
	@-echo 'Cleaning up unecessary files...' >&2
	@find \( -name '*~' -o -name 'vgcore.*' -o -name '*.gc*'	\
	-o -name 'a.out' -o -name '$(CODING_STYLE_LOG)' \) -delete

fclean:						clean
	@-echo 'Deleting $($(NAME)_TARGET)...' >&2
	@$(RM) -f $($(NAME)_TARGET)
	@-echo 'Deleting $($(NAME)_TESTS)...' >&2
	@$(RM) -f $($(NAME)_TESTS)
	@make fclean -C ./lib/Display/NCurses
	@make fclean -C ./lib/Display/SFML
	@make fclean -C ./lib/Display/SDL2
	@make fclean -C ./lib/Games/Snake
	@make fclean -C ./lib/Games/Nibbler

re:							fclean all

re_tests:					fclean tests_run

.PHONY:						all debug tests_run tests_debug		\
							clean fclean re re_tests libs		\
							coverage coding-style $(IGNORE_FILE)
