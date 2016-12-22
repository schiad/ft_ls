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
}

t_file	*ft_lstfadd(t_file *input, struct dirent *file, char *path)
{
	t_file	*tmp;
	if (!input)
	{
		if (!(tmp = (t_file *)malloc(sizeof(t_file) + 1)))
			return ((void *)NULL);
		tmp->name = file;
		tmp->path = path;
		tmp->next = NULL;
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
	t_file			*doss;
	t_file			*tmp;
	struct	dirent	*tmp2;

	files	= NULL;
	doss	= NULL;

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
		ft_insp_file(tmp);
		switch (tmp->prop->st_mode & S_IFMT)
		{
			case S_IFBLK:	ft_putstr("block device");		break;
			case S_IFCHR:	ft_putstr("character device");	break;
			case S_IFDIR:	
				ft_putstr("directory");
				if (!ft_strequ(tmp->name->d_name, "..") && !ft_strequ(tmp->name->d_name, "."))
					doss = ft_lstfadd(doss, tmp->name, path);
				break;
			case S_IFIFO:	ft_putstr("FIFO/pipe");			break;
			case S_IFLNK:	ft_putstr("symlink");			break;
			case S_IFREG:	ft_putstr("regular file");		break;
			case S_IFSOCK:	ft_putstr("socket");			break;
			default:		ft_putstr("unknown?");
		}
		ft_putstr("\t");
		ft_putstr(tmp->name->d_name);
		ft_putstr("\n");
		tmp = tmp->next;
	}
	closedir(dir);
	while (doss)
	{
		if (ft_strlen(doss->name->d_name))
			ft_list(ft_strjoin(path, ft_strjoin("/", doss->name->d_name)));
		doss = doss->next;
	}
}

void	ft_insp_file(t_file *file)
{
	char *tmp;
	char *pathfile;

	tmp = ft_strjoin(file->path, "/");
	pathfile = ft_strjoin(tmp, file->name->d_name);
	file->prop = (struct stat *)malloc(sizeof(struct stat) + 1);
	if (lstat(pathfile, file->prop) < 0)
	{
		ft_putstr("\e[41m");
		ft_putstr("error = ");
		ft_putstr(strerror(errno));
		ft_putstr("\e[0m");
	}
}
