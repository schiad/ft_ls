/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 16:34:47 by schiad            #+#    #+#             */
/*   Updated: 2016/10/21 17:20:57 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int	main (int argc, char **argv)
{
	DIR *dir;
	struct dirent *line;
	if (argc < 2)
		dir = opendir(".");
	else
		dir = opendir(argv[1]);

	if (dir == NULL)
	{
		printf ("\e[41m\e[32m\e[1m%s\n", strerror(errno));
		return -1;
	}
	else
	{
		printf ("\e[1m\e[4m\e[31mInode\t\e[32mLength\t\e[33mType\t\e[34mName\n");
		while ((line = readdir(dir)) != NULL)
		{
			printf ("\e[0m\e[31m%llu\t", (unsigned long long)line->d_ino);
			printf ("\e[32m%u\t", line->d_reclen);
			printf ("\e[33m%u\t", line->d_type);
			printf ("\e[34m%s\n", line->d_name);
		}
		(void)closedir(dir);
		printf ("\e[0m");
	}
	return 0;
}
