
NAME	= ft_ls

LIBFT	= ./libft/libft.a

all: libft $(NAME)

$(NAME):
	gcc ft_ls.c -o $(NAME) -I./libft/includes -L./libft -lft

libft: $(LIBFT)

$(LIBFT):
	echo "Complie LIBFT"
	make -C ./libft

fclean:
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
