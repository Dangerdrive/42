NAME			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC				=	ft_itoa ft_print_ptr ft_uitoa_base ft_unumlen_base ft_print_char ft_print_str ft_numlen ft_print_hex ft_print_unsig ft_printf ft_print_nbr 
SRCS 			=	$(addsuffix .c, $(SRC))

OBJ_DIR			=	obj
OBJS			=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				all

$(NAME):			$(OBJ_DIR) $(OBJS)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re


