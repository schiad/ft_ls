# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schiad <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/26 17:45:43 by schiad            #+#    #+#              #
#    Updated: 2016/10/26 17:52:19 by schiad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: inspect_file list

FLAGS = -Wall -Wextra -Werror

src_inspect_file = ft_inspect_file.c

src_list = ft_list.c

inspect_file:
	gcc $(FLAGS) -o $@ $(src_inspect_file)

list:
	gcc $(FLAGS) -o $@ $(src_list)

clean:

fclean:
	rm -f inspect_file list
 
re: fclean
	$(MAKE) all

