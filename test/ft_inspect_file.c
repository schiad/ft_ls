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

#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int	main (int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error specifie a file.\n");
		return -1;
	}
	else
	{
		struct stat buf;
		stat(argv[1], &buf);
		printf("\e[91mID dev. Minor: %d\n", minor(buf.st_dev));
		printf("\e[92mID dev. Major: %d\n", major(buf.st_dev));
		printf("\e[93mINODE: %ld\n", buf.st_ino);
		printf("\e[94mType: ");

		switch (buf.st_mode & S_IFMT)
		{
			case S_IFBLK:	printf("block device\n");		break;
			case S_IFCHR:	printf("character device\n");	break;
			case S_IFDIR:	printf("directory\n");			break;
			case S_IFIFO:	printf("FIFO/pipe\n");			break;
			case S_IFLNK:	printf("symlink\n");			break;
			case S_IFREG:	printf("regular file\n");		break;
			case S_IFSOCK:	printf("socket\n");				break;
			default:		printf("unknown?");
		}

		printf("\e[95mLink count: %ld\n", (long)buf.st_nlink);
		printf("\e[96mUID: %ld\n", (long)buf.st_uid);
		printf("\e[91mGID: %ld\n", (long)buf.st_gid);
		printf("\e[92mSize: %lld bytes\n", (long long)buf.st_size);
		printf("\e[93mPreferred I/O blocks size: %ld\n", (long)buf.st_blksize);
		printf("\e[94mBlocks allocated: %lld\n", (long long)buf.st_blocks);
		printf("\e[95mLast status change: %s", ctime(&buf.st_ctime));
		printf("\e[96mLast file access: %s", ctime(&buf.st_atime));
		printf("\e[91mLast file modification: %s", ctime(&buf.st_mtime));
		printf("\e[0m");
	}
	return 0;	
}
