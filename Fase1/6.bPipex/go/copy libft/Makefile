# CC		= gcc
# CFLAGS	= -Werror -Wextra -Wall
# NAME	= pipex

# SRC_PATH = src/
# OBJ_PATH = obj/

# SRC	= pipex.c \
# 	env_parsing.c \
# 	utils.c \
# 	init.c \
# 	file_handler.c \
# 	ft_putchar_fd.c \
# 	ft_putendl_fd.c \
# 	ft_putstr_fd.c \
# 	ft_split.c \
# 	ft_strjoin.c \
# 	ft_strlen.c \
# 	ft_strncmp.c \
# 	ft_strnstr.c \
# 	ft_substr.c \
# 	ft_strlcpy.c \
# 	ft_strdup.c \
# 	get_next_line.c \
# 	get_next_line_utils.c
# SRCS	= $(addprefix $(SRC_PATH), $(SRC))
# OBJ		= $(SRC:.c=.o)
# OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

# INC		= -I ./includes/

# all: $(NAME)

# $(OBJ_PATH)%.o: $(SRC_PATH)%.c
# 	@mkdir -p $(OBJ_PATH) $(OBJ_PATH)get_next_line/
# 	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) -o $@

# bonus: all

# clean:
# 	rm -rf $(OBJ_PATH)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all re clean fclean







# CC		= gcc
# CFLAGS	= -Werror -Wextra -Wall -I/libft -L/libft
# NAME	= pipex

# SRC_PATH = src/
# OBJ_PATH = obj/

# LIBFT_PATH		=	./libft
# LIBFT			=	$(LIBFT_PATH)/libft.a

# SRC	= pipex.c \
# 	env_parsing.c \
# 	utils.c \
# 	init.c \
# 	file_handler.c #\
# 	# ft_putchar_fd.c \
# 	# ft_putendl_fd.c \
# 	# ft_putstr_fd.c \
# 	# ft_split.c \
# 	# ft_strjoin.c \
# 	# ft_strlen.c \
# 	# ft_strncmp.c \
# 	# ft_strnstr.c \
# 	# ft_substr.c \
# 	# ft_strlcpy.c \
# 	# ft_strdup.c \
# 	# get_next_line.c \
# 	# get_next_line_utils.c
# SRCS	= $(addprefix $(SRC_PATH), $(SRC))
# OBJ		= $(SRC:.c=.o)
# OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

# INC		= -I ./includes/

# all: $(NAME)

# $(OBJ_PATH)%.o: $(SRC_PATH)%.c
# 	@mkdir -p $(OBJ_PATH) $(OBJ_PATH)get_next_line/
# 	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# $(NAME): $(OBJS) $(LIBFT) 
# 	$(CC) $(CFLAGS) $(OBJS) -o $@

# $(LIBFT):
# 					make -C $(LIBFT_PATH) all

# bonus: all

# clean:
# 					make -C $(LIBFT_PATH) clean
# 	rm -rf $(OBJ_PATH)

# fclean: clean
# 	make -C $(LIBFT_PATH) fclean
# 	rm -f $(NAME) 

# re: fclean all

# .PHONY: all re clean fclean





#no gpt version
# CC	  = cc
# CFLAGS  = -Werror -Wextra -Wall -Ilibft
# NAME	= pipex

# SRC_PATH = src/
# OBJ_PATH = obj/

# LIBFT_PATH	  = ./libft
# LIBFT		   = $(LIBFT_PATH)/libft.a

# SRC = pipex.c \
# 	env_parsing.c \
# 	utils.c \
# 	init.c \
# 	file_handler.c

# # Formatting
# BOLD 		= 		\033[1m

# SRCS	= $(addprefix $(SRC_PATH), $(SRC))
# OBJ	 = $(SRC:.c=.o)
# OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
# Libft
# 	@echo "✅ $(BOLD)Pipex created"

# $(OBJ_PATH)%.o: $(SRC_PATH)%.c
# 	@mkdir -p $(OBJ_PATH)
# 	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	

# $(NAME): $(OBJS) $(LIBFT)Libft
# 	@$(CC) $(CFLAGS) $(OBJS) -o $@ -L$(LIBFT_PATH) -lft
# 	@echo "✅ $(BOLD)Libft"

# $(LIBFT):
# 	@make -C $(LIBFT_PATH) all

# bonus: all

# clean:
# 	@make -C $(LIBFT_PATH) clean
# 	@rm -rf $(OBJ_PATH)
# 	@echo "🗑️  $(BOLD)Object files removed"

# fclean: clean
# 	@make -C $(LIBFT_PATH) fclean
# 	rm -f $(NAME)
# 	@echo "🗑️  $(BOLD)Pipex removed"

# .PHONY: all re clean fclean

# re: fclean all

# .PHONY: all re clean fclean

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
