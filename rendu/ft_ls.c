#include <dirent.h>
#include "ft_ls.h"
#include "./libft/includes/libft.h"

#define DEBUG 1

int	main(int argc, char **argv)
{
		//	ft_putstr_fd("main\n\0", 2);
		if (argc != 2)
				ft_list(".");
		else
				ft_list(argv[1]);
}

t_file	*ft_lstfadd(t_file *input, struct dirent *file)
{
		//	ft_putstr_fd("lstfadd\n", 2);
		t_file	*tmp;
		//	ft_putstr_fd("lstfadd\n", 2);
		if (!input)
		{
				//		ft_putstr_fd("if1\n", 2);
				if (!(tmp = (t_file *)malloc(sizeof(t_file) + 1)))
						return ((void *)NULL);
				//		ft_putstr_fd("end malloc\n", 2);
				tmp->name = file;
				tmp->next = NULL;
				return tmp;
		}
		else
		{
				tmp = input;
				while (tmp->next)
				{
						tmp = (t_file *)tmp->next;
				}
				tmp->next = ft_lstfadd(NULL, file);
		}
		return input;
}

void	ft_list(char *path)
{
		//	ft_putstr_fd("ft_list\n", 2);
		t_file			*files;
		DIR				*dir;
		t_file			*tmp;
		struct	dirent	*tmp2;

		files = NULL;

		dir = opendir(path);
		while ((tmp2 = readdir(dir)) != NULL)
		{
				files = ft_lstfadd(files, tmp2);
		}
		tmp = files;
		while (tmp)
		{
				ft_putstr(tmp->name->d_name);
				ft_insp_file(tmp);
				ft_putstr("insp\n");
				ft_putstr("insp\n");
				switch (tmp->prop->st_mode & S_IFMT)
				{
						case S_IFBLK:	ft_putstr("block device\n");		break;
						case S_IFCHR:	ft_putstr("character device\n");	break;
						case S_IFDIR:	ft_putstr("directory\n");			break;
						case S_IFIFO:	ft_putstr("FIFO/pipe\n");			break;
						case S_IFLNK:	ft_putstr("symlink\n");			break;
						case S_IFREG:	ft_putstr("regular file\n");		break;
						case S_IFSOCK:	ft_putstr("socket\n");				break;
						default:		ft_putstr("unknown?");
				}
				ft_putstr("\n");
				tmp = tmp->next;
		}

}

void	ft_insp_file(t_file *file)
{
		struct stat *tmp;

		tmp = file->prop;
		tmp = (struct stat *)malloc(sizeof(struct stat) + 1);
		if (lstat(file->name->d_name, tmp) < 0)
		{
			ft_putstr("\e[41m");
			ft_putstr("error = ");
			ft_putstr(strerror(errno));
		}
}
