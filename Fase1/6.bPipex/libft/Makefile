# Name of the library
NAME 		= 		libft.a

# Directories for source and header files
SRCDIR 		= 		.
INCDIR 		= 		.

# Compiler and flags
CC 			= 		cc
CFLAGS 		= 		-Wall -Wextra -Werror

# Source files and object files
SRCS		= 		$(addprefix $(SRCDIR)/, ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_itoa_base.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_numlen.c \
					ft_numlen_base.c \
					ft_putchar.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putstr.c \
					ft_putstr_fd.c \
					ft_split.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strtrim.c \
					ft_substr.c \
					ft_tolower.c \
					ft_toupper.c \
					ft_uitoa_base.c \
					ft_unumlen_base.c \
					get_next_line.c)

OBJS 		= 		$(SRCS:.c=.o)

B_SRCS 		= 		$(addprefix $(SRCDIR)/, ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c)

B_OBJS 		= 		$(B_SRCS:.c=.o)

# Rules
.PHONY: 			all clean fclean re bonus

all: 				$(NAME)

$(NAME): 			$(OBJS)
					ar rc $(NAME) $(OBJS)

$(SRCDIR)/%.o: 		$(SRCDIR)/%.c
					$(CC) $(CFLAGS) -c -o $@ $< -I $(INCDIR)

bonus: 				$(B_OBJS)
					ar rc $(NAME) $(B_OBJS)

clean:
					rm -f $(OBJS) $(B_OBJS)

fclean: 			clean
					rm -f $(NAME)

re: 				fclean all
