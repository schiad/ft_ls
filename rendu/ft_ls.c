#include <dirent.h>
#include "ft_ls.h"
#include "./libft/includes/libft.h"

int	main(int argc, char **argv)
{
		t_flags	*flags;

		flags = (t_flags *)malloc(sizeof(t_flags));
		flags->l = 1;
		if (argc != 2)
				ft_list(".", flags);
		else
				ft_list(argv[1], flags);
}

char	*ft_path_join(const char *str1, const char *str2)
{
		char	*tmp1;
		char	*result;
		int	i;
		int	j;

		result = ft_strnew(ft_strlen(str1) + ft_strlen(str2) + 1);
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

void	ft_lstffree(t_file *input)
{
		t_file	*tmp;
		t_file	*tmp2;

		tmp = input;
		tmp2 = NULL;

		while (tmp)
		{
				tmp2 = tmp;
				tmp = tmp->next;
				free(tmp2->prop);
				free(tmp2);
		}
}

void	ft_elemright(mode_t	mode)
{
		int		i;
		int		div[3];
		char	str[4];

		i = 0;
		div[0] = 1;
		div[1] = 10;
		div[2] = 100;
		str[3] = '\0';
		while (i < 3)
		{
				str[0] = (mode & (S_IRUSR / div[i])) ? 'r' : '-';

				str[1] = (mode & (S_IWUSR / div[i])) ? 'w' : '-';
				if (mode & S_IXUSR >> i)
				{
						str[2] = (mode & (S_ISUID / div[i])) ? 's' : 'x';
				}
				else
				{
						str[2] = (mode & (S_ISUID / div[i])) ? 'S' : '-';
				}
				if (i == 2)
				{
						if (str[2] == 's' || str[2] == 'S')
								str[2]++;
				}
				ft_putstr(str);
				i++;
		}
		ft_putchar('\t');
}

char	*ft_elemtype(t_file	*line)
{
		if (S_ISREG(line->prop->st_mode))
				return ("-");
		else if (S_ISDIR(line->prop->st_mode))
				return ("d");
		else if (S_ISCHR(line->prop->st_mode))
				return ("c");
		else if (S_ISBLK(line->prop->st_mode))
				return ("b");
		else if (S_ISFIFO(line->prop->st_mode))
				return ("p");
		else if (S_ISLNK(line->prop->st_mode))
				return ("l");
		else if (S_ISSOCK(line->prop->st_mode))
				return ("s");
}

void	ft_elemname(t_file *line)
{
		ft_putstr(line->name->d_name);
		ft_putchar('\n');
}

void	ft_printline(t_file	*line, t_flags	*flags)
{
		if (flags->l)
		{
				ft_putstr(ft_elemtype(line));
				ft_elemright(line->prop->st_mode);
		}
		ft_elemname(line);
}

int	ft_list(char *path, t_flags *flags)
{
		t_file		*files;
		DIR		*dir;
		t_file		*tmp;
		struct	dirent	*tmp2;
		char		*tmppath;

		files	= NULL;

		ft_putstr(path);
		ft_putstr(":\n\n");

		dir = opendir(path);
		if (dir == NULL)
		{
				ft_putstr_fd(strerror(errno), 2);
				ft_putstr_fd("\n\r", 2);
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
				ft_printline(tmp ,flags);
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
								ft_list(tmppath = ft_path_join(path, tmp->name->d_name), flags);
								ft_strdel(&tmppath);
						}
				}
				tmp = tmp->next;
		}
		closedir(dir);
		ft_lstffree(files);
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
				ft_putstr_fd("\e[41m", 2);
				ft_putstr_fd("error = ", 2);
				ft_putstr_fd(strerror(errno), 2);
				ft_putstr_fd("\e[0m", 2);
		}
		ft_strdel(&pathfile);
}
