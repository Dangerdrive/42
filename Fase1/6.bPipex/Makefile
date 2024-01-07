NAME	:=	pipex
CC		:=	cc
CFLAGS	:=	-Wextra -Wall -Werror -Wunreachable-code -Iinclude



LEAKS	:=	valgrind --leak-check=full --show-leak-kinds=all
SRCS	:= 	./*.c
			
OBJDIR	:=	obj
OBJS	:=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

.PHONY:	all clean fclean re valgrind

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a


bonus:	all

valgrind:	all
	@$(LEAKS)




all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	
$(LIBFT):
	make -C $(LIBFT_PATH) all	

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
					make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJDIR) $(NAME)

fclean:	clean
					make -C $(LIBFT_PATH) fclean
	@rm -rf $(NAME)

re:		fclean all








# COLOR_INFO = \033[1;36m
# COLOR_SUCCESS = \033[1;32m
# COLOR_RESET = \033[0m

# EMOJI_INFO = 🌈
# EMOJI_SUCCESS = 🎉
# EMOJI_CLEAN = 🧹
# EMOJI_RUN = 🚀

# all: $(NAME)

# $(NAME): $(MLX) $(LIBFT) $(OBJS)
# 	@printf "$(COLOR_INFO)$(EMOJI_INFO)  Compiling $(NAME)...$(COLOR_RESET)\t"
# 	@cc $(OBJS) $(LIBS) $(INCLUDES) $(LINKERS) $(CODAM_FLAGS) -o $@
# 	@sleep 0.25
# 	@printf "✅\n"

# build/%.o: src/%.c incl/fractol.h incl/frctl_config.h incl/structs.h
# 	@mkdir -p $(@D)
# 	@gcc $(INCLUDES) $(CODAM_FLAGS) -c $< -o $@

# $(MLX):
# 	@printf "$(COLOR_INFO)$(EMOJI_INFO)  Initializing submodules...$(COLOR_RESET)\t"
# 	@git submodule update --init --recursive > /dev/null
# 	@sleep 0.25
# 	@printf "✅\n"
# 	@printf "$(COLOR_INFO)$(EMOJI_INFO)  Building MLX42...$(COLOR_RESET)\t\t"
# 	@cmake -S MLX42 -B MLX42/build -DGLFW_FETCH=1 > /dev/null
# 	@cmake --build MLX42/build --parallel > /dev/null
# 	@sleep 0.25
# 	@printf "✅\n"

# $(LIBFT):
# 	@printf "$(COLOR_INFO)$(EMOJI_INFO)  Building Libft...$(COLOR_RESET)\t\t"
# 	@$(MAKE) -C libft > /dev/null
# 	@sleep 0.25
# 	@printf "✅\n"

# clean:
# 	@printf "$(COLOR_INFO)$(EMOJI_CLEAN)  Cleaning up...$(COLOR_RESET)\t\t"
# 	@rm -rf MLX42/build
# 	@$(MAKE) -C libft clean > /dev/null
# 	@rm -rf build
# 	@sleep 0.25
# 	@printf "✅\n"

# fclean: clean
# 	@printf "$(COLOR_INFO)$(EMOJI_CLEAN)  Removing executable...$(COLOR_RESET)\t"
# 	@$(MAKE) -C libft fclean > /dev/null
# 	@rm -f $(NAME)
# 	@sleep 0.25
# 	@printf "✅\n"

# run: $(NAME)
# 	@printf "$(COLOR_INFO)$(EMOJI_RUN)  Compiled and started $(NAME)...$(COLOR_RESET)"
# 	@./$(NAME) 1

# norm:
# 	@norminette $(SRCS) incl/fractol.h libft

# re: fclean $(NAME)

# bonus: all

# module-update:
# 	@git submodule update --remote --merge

# .PHONY: all clean fclean run re module-update



#./pipex infile cmd1 cmd2 outfile
