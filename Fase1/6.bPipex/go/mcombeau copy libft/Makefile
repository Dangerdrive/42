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



CC	  = gcc
CFLAGS  = -Werror -Wextra -Wall -Ilibft
NAME	= pipex

SRC_PATH = src/
OBJ_PATH = obj/

LIBFT_PATH	  = ./libft
LIBFT		   = $(LIBFT_PATH)/libft.a

SRC = pipex.c \
	env_parsing.c \
	utils.c \
	init.c \
	file_handler.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ	 = $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

INC	 = -I ./includes/

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -L$(LIBFT_PATH) -lft

$(LIBFT):
	make -C $(LIBFT_PATH) all

bonus: all

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
