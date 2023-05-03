NAME = ft_display_file

# Source files and object files
SRCS = $(wildcard srcs/*.c)
OBJS = $(SRCS:.c=.o)

# Rules
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME)

srcs/%.o: srcs/%.c
	cc -Wall -Wextra -Werror -c -o $@ $< -I includes

clean:
	rm -f */*.o

fclean: clean
	rm -f *.a

re: fclean all