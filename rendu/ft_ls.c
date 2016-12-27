#include <dirent.h>
#include "ft_ls.h"
#include "./libft/includes/libft.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_list(".");
	else
		ft_list(argv[1]);
}

char	*ft_path_join(const char *str1, const char *str2)
{
	char	*tmp1;
	char	*result;
	int	i;
	int	j;

	result = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 2));
	i = 0;
	j = 0;
	while (str1[i])
	{
		if (!(str1[i] == '/' && (str1[i + 1] == '/' || str1[i + 1] == '\0')))
		{
			result[j++] = str1[i];
		}
		i++;
	}
	result[j] = '/';
	j++;
	i = 0;
	while (str2[i])
	{
		result[j++] = str2[i];
		i++;
	}
	result[j] = '\0';

	return result;
}

t_file	*ft_lstfadd(t_file *input, struct dirent *file, char *path)
{
	t_file	*tmp;
	if (!input)
	{
		if (!(tmp = (t_file *)malloc(sizeof(t_file))))
			return ((void *)NULL);
		tmp->name = file;
		tmp->path = path;
		tmp->doss = 0;
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
	t_file		*files;
	DIR		*dir;
	t_file		*tmp;
	struct	dirent	*tmp2;
	char		*tmppath;

	files	= NULL;

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
					if ((ft_strequ(tmp->name->d_name, "..") == 0) && (ft_strequ(tmp->name->d_name, ".") == 0))
						tmp->doss = 1;
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
	tmp = files;
	while (tmp)
	{
		if (tmp->doss)
		{
			if (ft_strlen(tmp->name->d_name))
			{
				ft_putstr("\n");
				ft_list(tmppath = ft_path_join(path, tmp->name->d_name));
				ft_strdel(&tmppath);
			}
		}
		tmp = tmp->next;
	}
	closedir(dir);
}

void	ft_insp_file(t_file *file)
{
	char *tmp;
	char *pathfile;

	tmp = ft_strjoin(file->path, "/");
	pathfile = ft_strjoin(tmp, file->name->d_name);
	file->prop = (struct stat *)malloc(sizeof(struct stat));
	if (lstat(pathfile, file->prop) < 0)
	{
		ft_putstr("\e[41m");
		ft_putstr("error = ");
		ft_putstr(strerror(errno));
		ft_putstr("\e[0m");
	}
}
