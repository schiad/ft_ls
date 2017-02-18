# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schiad <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/05 13:10:16 by schiad            #+#    #+#              #
#    Updated: 2017/02/18 10:13:58 by schiad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_ls

CC			= gcc
FLAGS		= -Wall -Wextra -Werror

SRC_DIR		= ./sources/
INC_DIR 	= ./includes/

LIBFT		= ./libft/libft.a
LIBFT_INC	= ./libft/includes
LIBFT_DIR	= ./libft

all: libft $(NAME)

$(NAME):
	@echo "Compiling ft_ls project"
	@$(CC) $(FLAGS) $(SRC_DIR)ft_ls.c -o $(NAME) -I$(LIBFT_INC) \
	-L$(LIBFT_DIR) -lft -Ofast
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
