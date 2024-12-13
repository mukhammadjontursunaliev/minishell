# Program file name
NAME	= minishell

# Compiler and compilation flags
CC		= clang
CFLAGS	= -Werror -Wextra -Wall -gdwarf-4 -g

# Build files and directories
SRC_PATH = ./sources/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
SRC		= 	main.c \
			utils/init_data.c \
			env/env.c \
			env/env_set.c \
			builtins/export_builtin.c \
			builtins/unset_builtin.c \
			builtins/cd_builtin.c \
			builtins/env_builtin.c \
			builtins/pwd_builtin.c \
			builtins/echo_builtin.c \
			builtins/exit_builtin.c \
			execution/execute.c \
			execution/execute_cmd.c \
			execution/execute_utils.c \
			execution/parse_path.c \
			utils/exit.c \
			parser/cmd_lst_utils_cleanup.c \
			lexer/token_lst_utils.c \
			lexer/parse_user_input.c \
			utils/error.c \
			utils/cleanup.c \
			signals/signals.c \
			redirections/file_io.c \
			redirections/pipe.c \
			debug/debug.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INC		= -I $(INC_PATH) -I $(LIBFT_PATH)

# Libft files and directories
LIBFT_PATH = ./libft/
LIBFT = ./libft/libft.a

# Main rule
all: $(OBJ_PATH) $(LIBFT) $(NAME)

# Objects directory rule
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_PATH)/builtins
	mkdir -p $(OBJ_PATH)/env
	mkdir -p $(OBJ_PATH)/lexer
	mkdir -p $(OBJ_PATH)/execution
	mkdir -p $(OBJ_PATH)/utils
	mkdir -p $(OBJ_PATH)/signals
	mkdir -p $(OBJ_PATH)/debug
	mkdir -p $(OBJ_PATH)/redirections
	mkdir -p $(OBJ_PATH)/parser


# Objects rule
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Project file rule
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC) $(LIBFT) -l readline

# Libft rule
$(LIBFT):
	make -C $(LIBFT_PATH)

# Clean up build files rule
clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean

# Remove program executable
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

# Clean + remove executable
re: fclean all

.PHONY: all re clean fclean