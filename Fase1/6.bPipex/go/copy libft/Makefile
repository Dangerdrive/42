#suppress directory messages
MAKEFLAGS += --no-print-directory

CC        = cc
CFLAGS    = -Werror -Wextra -Wall -Ilibft
NAME      = pipex

SRC_PATH  = src/
OBJ_PATH  = obj/

INC		= -I ./includes/

LIBFT_PATH   = ./libft
LIBFT        = $(LIBFT_PATH)/libft.a

SRC = pipex.c \
      env_parsing.c \
      utils.c \
      init.c \
      file_handler.c

# Formatting
BOLD      = \033[1m
NO_COLOR  = \033[0m

SRCS  = $(addprefix $(SRC_PATH), $(SRC))
OBJ   = $(SRC:.c=.o)
OBJS  = $(addprefix $(OBJ_PATH), $(OBJ))

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	@echo  "$(BOLD)✔️ Compiling $<$(NO_COLOR)"

all: 
	@echo ""
	@$(MAKE) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -o $@ -L$(LIBFT_PATH) -lft
	@echo  "\n✅ $(BOLD)Pipex compiled$(NO_COLOR)"

$(LIBFT):
	@make -C $(LIBFT_PATH) all
	@echo  "\n✔️ $(BOLD)Libft compiled$(NO_COLOR)"

bonus: all

clean:
	@echo ""
	@make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo  "🗑️  $(BOLD)Object files removed$(NO_COLOR)"

fclean: clean
	@echo ""
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@echo  "🗑️  $(BOLD)Pipex removed$(NO_COLOR)"

re: fclean all

.PHONY: all re clean fclean bonus
