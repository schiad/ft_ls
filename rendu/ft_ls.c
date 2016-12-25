#include <dirent.h>
#include "ft_ls.h"
#include "./libft/includes/libft.h"

#define DEBUG 1

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_list(".");
	else
		ft_list(argv[1]);
	return (0);
}

t_file	*ft_lstfadd(t_file *input, struct dirent *file, char *path)
{
	t_file	*tmp;
	if (!input)
	{
		if (!(tmp = (t_file *)malloc(sizeof(t_file))))
			return ((void *)NULL);
		tmp->d_ino = file->d_ino;
		tmp->d_off = file->d_off;
		tmp->d_reclen = file->d_reclen;
		tmp->d_type = file->d_type;
		tmp->d_name = ft_strdup(file->d_name);
//		tmp->d_name = file->d_name;
		ft_putstr(tmp->d_name);
		tmp->path = path;
		tmp->next = NULL;
		tmp->dir = 0;
		ft_insp_file(tmp);
		if ((tmp->st_mode & S_IFMT) == S_IFDIR)
		{
			if (0 == ft_strequ(tmp->d_name, "..") &&
			0 == ft_strequ(tmp->d_name, "."))
				tmp->dir = 1;
		}
		return tmp;
	}
	else
	{
		tmp = input;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = ft_lstfadd(NULL, file, path);
	}
	return input;
}

int	ft_list(char *path)
{
	t_file			*files;
	DIR				*dir;
	t_file			*tmp;
	struct	dirent	*tmp2;

	files	= NULL;

	ft_putstr("\n\n");
	ft_putstr(path);
	ft_putstr(":\n");

	dir = opendir(path);
	if (dir == NULL)
	{
		ft_putstr(strerror(errno));
		ft_putstr("\n");
		return errno;
	}
	while ((tmp2 = readdir(dir)) != NULL)
	{
		files = ft_lstfadd(files, tmp2, path);
	}
	tmp = files;
	while (tmp)
	{
		switch (tmp->st_mode & S_IFMT)
		{
			case S_IFBLK:	ft_putstr("block device");		break;
			case S_IFCHR:	ft_putstr("character device");	break;
			case S_IFDIR:	ft_putstr("directory");			break;
			case S_IFIFO:	ft_putstr("FIFO/pipe");			break;
			case S_IFLNK:	ft_putstr("symlink");			break;
			case S_IFREG:	ft_putstr("regular file");		break;
			case S_IFSOCK:	ft_putstr("socket");			break;
			default:		ft_putstr("unknown?");
		}
		ft_putstr("\t");
		ft_putstr(tmp->d_name);
		ft_putstr("\t");
		ft_putstr(tmp->path);
		ft_putstr("\n");
		tmp = tmp->next;
	}
	closedir(dir);
	tmp = files;
	while (tmp)
	{
		if (tmp->dir)
			ft_list(ft_strjoin(path, ft_strjoin("/", tmp->d_name)));
		tmp = tmp->next;
	}
}

void	ft_insp_file(t_file *file)
{
	char		*tmp;
	char		*pathfile;
	struct stat	*prop;

	tmp = ft_strjoin(file->path, "/");
	pathfile = ft_strjoin(tmp, file->d_name);
	if (lstat(pathfile, prop) < 0)
	{
		ft_putstr("\e[41m");
		ft_putstr("error = ");
		ft_putstr(strerror(errno));
		ft_putstr("\e[0m");
	}
	file->st_dev = prop->st_dev;
	file->st_ino = prop->st_ino;
	file->st_mode = prop->st_mode;
	file->st_nlink = prop->st_nlink;
	file->st_uid = prop->st_uid;
	file->st_gid = prop->st_gid;
	file->st_rdev = prop->st_rdev;
	file->st_size = prop->st_size;
	file->st_blksize = prop->st_blksize;
	file->st_blocks = prop->st_blocks;
	file->st_atim = prop->st_atim;
	file->st_mtim = prop->st_mtim;
	file->st_ctim = prop->st_ctim;
}
