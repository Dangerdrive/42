# # Name of the program
# NAME = fractol

# # Directories for source and header files
# SRCDIR = .
# INCDIR = .

# # Compiler and flags
# CC = cc
# CFLAGS = -Wall -Wextra -Werror

# # Source files and object files
# SRCS = $(addprefix $(SRCDIR)/, fractol.c)
# #		  ft_tolower.c \
# #		  ft_toupper.c)

# OBJS = $(SRCS:.c=.o)

# %.o: %.c
# 	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -lm -lmlx -lXext -lX11 -L minilibx-linux -o $(NAME)

##########################

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


NAME	:= fractol
CC = cc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g -O3 -Iinclude
LDFLAGS = -ldl -lglfw -pthread -lm
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= 	./colors.c \
			./f_julia.c \
			./f_mandelbrot.c \
			./fractal_init.c \
			./guide.c \
			./fractals.c \
			./fractol.c \
			./hooks.c \
			./main.c \
			./math.c \
			./string_utils.c
OBJS	:= ${SRCS:.c=.o}s

.PHONY: all, clean, fclean, re, libmlx, bonus

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all
