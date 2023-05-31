# Name of the library
NAME = get_next_line.a

# Directories for source and header files
SRCDIR = .
INCDIR = .

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files and object files
SRCS = $(addprefix $(SRCDIR)/, get_next_line.c \
		  get_next_line_utils.c)
  
OBJS = $(SRCS:.c=.o)

B_SRCS = $(addprefix $(SRCDIR)/, get_next_line_bonus.c \
get_next_line_utils_bonus.c)

B_OBJS = $(B_SRCS:.c=.o)

# Rules
.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCDIR)

bonus: $(B_OBJS)
	ar rc $(NAME) $(B_OBJS)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
