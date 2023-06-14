# Name of the library
NAME 		= 		libftprintf.a

# Directories
SRCDIR 		= 		./source
INCDIR 		= 		./include
OBJDIR 		= 		./.object
LIBFTDIR 	= 		./libft

# Compiler and flags
CC 			= 		cc
CFLAGS 		= 		-Wall -Wextra -Werror
AR 			= 		ar
ARFLAGS 	= 		rcs

# Source files
SRCS 		= 		$(addprefix $(SRCDIR)/, ft_printf.c \
					ft_printf_utils.c \)

LIBFT			=	$(LIBFTDIR)/libft.a

OBJS		=		$(SRCS:%.c=$(OBJDIR)/%.o)


# $(SRCDIR)/%.o: 		$(SRCDIR)/%.c
# 					$(CC) $(CFLAGS) -c -o $@ $< -I $(INCDIR)

$(OBJDIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

all: 				$(NAME)

# bonus:			all

$(NAME):			$(LIBFT) $(OBJDIR) $(OBJS)
					cp	$(LIBFT) $(NAME)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
					make -C $(LIBFTDIR) all

$(OBJDIR):
					mkdir -p $(OBJDIR)



# bonus: 				$(B_OBJS)
# 					$(AR) $(ARFLAGS) $(B_OBJS)

clean:
					make -C $(LIBFTDIR) clean
					rm -rf $(OBJDIR)

fclean: 			clean
					make -C $(LIBFTDIR) fclean
					rm -rf $(NAME)

re: 				fclean all

libft:				$(LIBFT)
					
# Rules
.PHONY: 			all clean fclean re libft