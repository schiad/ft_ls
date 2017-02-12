# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schiad <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/05 13:10:16 by schiad            #+#    #+#              #
#    Updated: 2017/02/05 13:15:20 by schiad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

LIBFT	= ./libft/libft.a

FLAGS	= -Wall -Wextra -Werror

all: libft $(NAME)

noflags: libft
	@echo "Compiling ft_ls project"
	@gcc ft_ls.c -o $(NAME) -I./libft/includes -L./libft -lft
	@echo "ft_ls compiled. ENJOY"

$(NAME):
	@echo "Compiling ft_ls project"
	@gcc $(FLAGS) ft_ls.c -o $(NAME) -I./libft/includes -L./libft -lft
	@echo "ft_ls compiled. ENJOY"

libft: $(LIBFT)

$(LIBFT):
	@echo "Call LIBFT to compile."
	@make --no-print-directory -C ./libft

fclean:
	@echo "Call LIBFT to fclean."
	@make fclean --no-print-directory -C ./libft
	@rm -f $(NAME)
	@echo "ft_ls deleted :-(."
	@make fclean --no-print-directory -C ../test

re: fclean all
