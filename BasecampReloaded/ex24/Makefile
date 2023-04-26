# Name of the library
NAME = libft.a


# Source files and object files
SRCS = $(wildcard srcs/*.c)
OBJS = $(SRCS:.c=.o)

# Rules
#.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

srcs/%.o: srcs/%.c
	cc -Wall -Wextra -Werror -c -o $@ $< -I includes

clean:
	rm -f */*.o

fclean: clean
	rm -f *.a

re: fclean all