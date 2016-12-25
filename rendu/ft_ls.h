

#ifndef FT_LS_H
# define FT_LS_H

# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <errno.h>
# include "libft.h"

typedef	struct	s_file
{
	char			*path;
	char			*d_name;
	int				dir;
	ino_t			d_ino;
	off_t			d_off;
	unsigned short	d_reclen;
	unsigned char	d_type;
	dev_t			st_dev;
	ino_t			st_ino;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	dev_t			st_rdev;
	off_t			st_size;
	blksize_t		st_blksize;
	blkcnt_t		st_blocks;
	struct timespec st_atim;
	struct timespec st_mtim;
	struct timespec st_ctim;
	struct	s_file	*next;
}				t_file;

t_file  *ft_lstfadd(t_file *input, struct dirent *file, char *path);
int		ft_list(char *path);
void	ft_insp_file(t_file *file);

#endif
