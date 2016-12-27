# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schiad <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/29 02:24:02 by schiad            #+#    #+#              #
#    Updated: 2015/12/04 23:10:10 by schiad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

SRC = ft_memset.c\
	  ft_bzero.c\
	  ft_memcpy.c\
	  ft_memccpy.c\
	  ft_memmove.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_strlen.c\
	  ft_strdup.c\
	  ft_strcpy.c\
	  ft_strncpy.c\
	  ft_strcat.c\
	  ft_strncat.c\
	  ft_strlcat.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_strstr.c\
	  ft_strnstr.c\
	  ft_strcmp.c\
	  ft_strncmp.c\
	  ft_atoi.c\
	  ft_isalpha.c\
	  ft_isdigit.c\
	  ft_isalnum.c\
	  ft_isascii.c\
	  ft_isprint.c\
	  ft_toupper.c\
	  ft_tolower.c\
	  ft_memalloc.c\
	  ft_memdel.c\
	  ft_strnew.c\
	  ft_strdel.c\
	  ft_strclr.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_strsub.c\
	  ft_strjoin.c\
	  ft_strtrim.c\
	  ft_strsplit.c\
	  ft_itoa.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_putendl.c\
	  ft_putnbr.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_fd.c\
	  ft_lstnew.c\
	  ft_lstdelone.c\
	  ft_lstdel.c\
	  ft_lstadd.c\
	  ft_lstiter.c\
	  ft_lstmap.c


OBJ = $(SRC:.c=.o)

HEADER = $(NAME:.a=.h)

INCLUDES = ./includes

all: $(NAME)

FLAGS = -Wall -Wextra -Werror

$(NAME):
	@echo "Compiling all sources in objects files."
	@$(CC) -FLAGS -I$(INCLUDES) -c $(SRC)
	@echo "Objects files compiled."
	@echo "Creating libtf.a file of libft."
	@ar rc $(NAME) $(OBJ)
	@echo "libft.a created."
	@echo "Indexing libft.a."
	@ranlib $(NAME)
	@echo "libft.a indexed enjoy."

clean:
	@echo "Deleting objects files."
	@rm -f $(OBJ)
	@echo "Objects files deleted."

fclean: clean
	@echo "Deleting libft.a."
	@rm -f $(NAME)
	@echo "libft.a deleted :-(."

re: fclean all

.PHONY: clean fclean re
