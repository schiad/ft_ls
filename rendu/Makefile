# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schiad <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/05 13:10:16 by schiad            #+#    #+#              #
#    Updated: 2017/02/19 13:55:51 by schiad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_ls

CC			= gcc
FLAGS		= -Wall -Wextra -Werror

SRC_DIR		= ./srcs/
SRC			= $(SRC_DIR)ft_ls.c\
			  $(SRC_DIR)elem_functions.c\
			  $(SRC_DIR)help.c\
			  $(SRC_DIR)init.c\
			  $(SRC_DIR)list_help.c\
			  $(SRC_DIR)parse_input.c\
			  $(SRC_DIR)print.c\
			  $(SRC_DIR)right_print.c

LIBFT		= ./libft/libft.a
LIBFT_INC	= ./libft/include
LIBFT_DIR	= ./libft

all: $(NAME)

$(NAME): libft
	@echo "Compiling ft_ls project"
	@cd $(SRC_DIR)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) -I$(LIBFT_INC) \
	-L$(LIBFT_DIR) -lft
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

clean:
	@echo "Call LIBFT to clean."
	@make clean --no-print-directory -C ./libft

re: fclean all
