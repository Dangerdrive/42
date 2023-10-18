NAME	:=	fractol
CC		:=	cc
CFLAGS	:=	-Wextra -Wall -Werror -Wunreachable-code -Ofast -Iinclude
LDFLAGS :=	-ldl -lglfw -pthread -lm
LIBMLX	:= 	./MLX42/build
SRCS	:= 	./colors.c \
			./f_julia.c \
			./f_mandelbrot.c \
			./f_tricorn.c \
			./fractal_init.c \
			./hooks.c \
			./main.c \
			./math.c \
			./messages.c \
			./string_utils.c

OBJDIR	:=	obj
OBJS	:=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

.PHONY:	all clean fclean re

bonus:	all

all:	$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) -L$(LIBMLX) -lmlx42 $(LDFLAGS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR) $(NAME)

fclean:	clean
	@rm -rf $(NAME)

re:		clean all