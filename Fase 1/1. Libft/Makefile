# Name of the library
NAME = libft.a

# Directories for source and header files
SRCDIR = .
INCDIR = .

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files and object files
SRCS = $(addprefix $(SRCDIR)/, ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memccpy.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strlen.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strnstr.c \
		  ft_strncmp.c \
		  ft_strcmp.c \
		  ft_atoi.c \
		  ft_atoll.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strjoin1.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_lltoa.c \
		  ft_strmapi.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c)
OBJS = $(SRCS:.c=.o)

# Rules
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCDIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all