NAME	:=	fractol
CC		:=	cc
CFLAGS	:=	-Wextra -Wall -Werror -Wunreachable-code -Ofast -Iinclude
LDFLAGS :=	-ldl -lglfw -pthread -lm
LIBMLX	:= 	./MLX42Codam
LEAKS	:=	valgrind --leak-check=full --show-leak-kinds=all  --suppressions=./MLX42Codam/suppress.sup ./fractol mandelbrot
SRCS	:= 	./colors.c \
			./f_julia.c \
			./f_julia_glitch.c \
			./f_mandelbrot.c \
			./f_mandelbrot_glitch.c \
			./f_tricorn.c \
			./f_tricorn_glitch.c \
			./fractal_init.c \
			./hooks.c \
			./main.c \
			./math.c \
			./messages.c \
			./string_utils.c

OBJDIR	:=	obj
OBJS	:=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

.PHONY:	all clean fclean re valgrind run

bonus:	all

valgrind:	all
	@$(LEAKS)



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

re:		fclean all

run:	re
	@./fractol mandelbrot
re:		clean all