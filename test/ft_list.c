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
		printf ("%s\n", strerror_r(errno));
		return -1;
	}
	else
	{
		printf ("Inode\tLength\tType\tName\n");
		while ((line = readdir(dir)) != NULL)
		{
			printf ("%lu\t", line->d_ino);
			printf ("%u\t", line->d_reclen);
			printf ("%u\t", line->d_type);
			printf ("%s", line->d_name);
			printf ("\n");
		}
		(void)closedir(dir);
	}
	return 0;
}
