# Name of the program
NAME = fractol

# Directories for source and header files
SRCDIR = .
INCDIR = .

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files and object files
SRCS = $(addprefix $(SRCDIR)/, fractol.c)
#		  ft_tolower.c \
#		  ft_toupper.c)

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lm -lmlx -lXext -lX11 -L minilibx-linux -o $(NAME)



# Rules
#.PHONY: all clean fclean re bonus
#
#all: $(NAME)
#
#$(NAME): $(OBJS)
#	ar rc $(NAME) $(OBJS)
#
#$(SRCDIR)/%.o: $(SRCDIR)/%.c
#	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCDIR)
#
#
#bonus: $(B_OBJS)
#	ar rc $(NAME) $(B_OBJS)
#
#clean:
#	rm -f $(OBJS) $(B_OBJS)
#
#fclean: clean
#	rm -f $(NAME)
#
#re: fclean all
