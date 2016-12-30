
NAME	= ft_ls

LIBFT	= ./libft/libft.a

all: libft $(NAME)

$(NAME):
	@echo "Compiling ft_ls project"
	@gcc ft_ls.c -o $(NAME) -I./libft/includes -L./libft -lft
	@echo "ft_ls compiled. ENJOY"

libft: $(LIBFT)

$(LIBFT):
	@echo "Call LIBFT to compile."
	@make --no-print-directory -C ./libft

fclean:
	@echo "Call LIBFT to fclean."
	@make clean --no-print-directory -C ./libft
	@rm -f $(NAME)
	@echo "ft_ls deleted :-(."

re: fclean all
