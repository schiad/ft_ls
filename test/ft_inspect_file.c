/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 19:17:03 by schiad            #+#    #+#             */
/*   Updated: 2016/10/21 19:17:04 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

int	main (int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error specifie a file.\n");
		return -1:
	}
	else
	{
		struct stat *buf;
		stat
	}
	return 0;	
}
