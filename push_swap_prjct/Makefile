# Standard
NAME                = push_swap

# Directories
INC                 = .
SRC_DIR             = .
OBJ_DIR             = obj/

# Compiler and CFlags
CC                  = gcc
CFLAGS              = -Wall -Werror -Wextra -I$(INC)
RM                  = rm -f

# Source Files
MOVES_DIR           =   $(SRC_DIR)/moves/pushing.c \
                        $(SRC_DIR)/moves/rotating.c \
                        $(SRC_DIR)/moves/rrotating.c \
                        $(SRC_DIR)/moves/swaping.c

PARSING_DIR         =   $(SRC_DIR)/parsing/libft_tools.c \
                        $(SRC_DIR)/parsing/split.c \
                        $(SRC_DIR)/parsing/validating.c

TOOLS_DIR           =   $(SRC_DIR)/tools/initialiase_a_2_b.c \
                        $(SRC_DIR)/tools/initialiase_b_2_a.c \
                        $(SRC_DIR)/tools/stack_helpers.c \
                        $(SRC_DIR)/tools/stack_helpers2.c

TURKALGO_DIR        =   $(SRC_DIR)/turkalgo/three_sort.c \
                        $(SRC_DIR)/turkalgo/turk_sort.c

MAIN_DIR            =   $(SRC_DIR)/push_swap.c

# Concatenate all source files
SRCS                = $(MOVES_DIR) $(PARSING_DIR) $(TOOLS_DIR) $(TURKALGO_DIR) $(MAIN_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJS                = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Build rules
start:
					@make all

all:                $(NAME)

$(NAME):            $(OBJS)
					@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:      $(SRC_DIR)/%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)

fclean:             clean
					@$(RM) $(NAME)

re:                 fclean all

# Phony targets represent actions not files
.PHONY:             start all clean fclean re
