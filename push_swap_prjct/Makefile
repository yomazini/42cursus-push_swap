NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
OBJ_DIR = obj
HEADER_PUSH_SWAP = push_swap.h
HEADER_CHECKER = src_checker/checker.h

SHARED_OBJS = \
	$(OBJ_DIR)/moves/pushing.o \
	$(OBJ_DIR)/moves/rotating.o \
	$(OBJ_DIR)/moves/rrotating.o \
	$(OBJ_DIR)/moves/swaping.o \
	$(OBJ_DIR)/parsing/libft_tools.o \
	$(OBJ_DIR)/parsing/libft_tools1.o \
	$(OBJ_DIR)/parsing/split.o \
	$(OBJ_DIR)/parsing/validating.o \
	$(OBJ_DIR)/parsing/validating2.o \
	$(OBJ_DIR)/tools/initialiase_a_2_b.o \
	$(OBJ_DIR)/tools/initialiase_b_2_a.o \
	$(OBJ_DIR)/tools/stack_helpers.o \
	$(OBJ_DIR)/tools/stack_helpers2.o \
	$(OBJ_DIR)/turkalgo/three_sort.o \
	$(OBJ_DIR)/turkalgo/turk_sort.o

PUSH_SWAP_OBJS = $(SHARED_OBJS) \
	$(OBJ_DIR)/push_swap.o

CHECKER_OBJS = $(SHARED_OBJS) \
	$(OBJ_DIR)/src_checker/checker.o \
	$(OBJ_DIR)/src_checker/execute_commands.o \
	$(OBJ_DIR)/src_checker/get_next_line.o \
	$(OBJ_DIR)/src_checker/libft_tools_4checker.o \
	$(OBJ_DIR)/src_checker/get_next_line_utils.o

all: $(NAME)

$(NAME): $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

checker: $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

bonus: checker

$(OBJ_DIR)/%.o: %.c $(HEADER_PUSH_SWAP)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/src_checker/%.o: src_checker/%.c $(HEADER_CHECKER) $(HEADER_PUSH_SWAP)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) checker

re: fclean all
