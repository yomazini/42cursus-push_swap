NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

OBJ_DIR = obj
HEADER = push_swap.h

OBJS = \
	$(OBJ_DIR)/moves/pushing.o \
	$(OBJ_DIR)/moves/rotating.o \
	$(OBJ_DIR)/moves/rrotating.o \
	$(OBJ_DIR)/moves/swaping.o \
	$(OBJ_DIR)/parsing/libft_tools.o \
	$(OBJ_DIR)/parsing/split.o \
	$(OBJ_DIR)/parsing/validating.o \
	$(OBJ_DIR)/tools/initialiase_a_2_b.o \
	$(OBJ_DIR)/tools/initialiase_b_2_a.o \
	$(OBJ_DIR)/tools/stack_helpers.o \
	$(OBJ_DIR)/tools/stack_helpers2.o \
	$(OBJ_DIR)/turkalgo/three_sort.o \
	$(OBJ_DIR)/turkalgo/turk_sort.o \
	$(OBJ_DIR)/push_swap.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
