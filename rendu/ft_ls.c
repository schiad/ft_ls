#include <dirent.h>
#include "ft_ls.h"
#include "./libft/includes/libft.h"

int	main(int argc, char **argv)
{
	t_flags	*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	flags->l = 1;
	flags->R = 1;
	flags->r = 0;
	flags->a = 1;
	flags->s = 1;
	flags->exec = argv[0];
	if (argc != 2)
		list(".", flags);
	else
		list(argv[1], flags);
	ft_memdel((void **)&flags);
	return 0;
}

void	sort_name(t_file **file, t_flags *flags)
{
	t_file	*tmp[5];
	t_file	*iter;
	int	ok;
	int	sort;

	ok = 0;
	tmp[0] = *file;
	while (!ok)
	{
		ft_putstr_fd("!ok\t", 2);
		ok = 1;
		iter = tmp[0];
		while (iter->next && ok)
		{
			tmp[2] = iter->next->next;
			ft_putstr_fd(iter->name->d_name, 2);
			ft_putstr_fd("\tvs\t", 2);
			ft_putstr_fd(iter->next->name->d_name, 2);
			sort = ft_strcmp(iter->name->d_name, iter->next->name->d_name);
			if (flags->r)
				sort = -sort;
			if (sort > 0)
			{
				ft_putstr_fd("\tsort\t", 2);
				ok = 0;
				if (tmp[0] == iter)
				{
					ft_putstr_fd("first replace\n", 2);
					tmp[0] = iter->next;
					tmp[0]->next = iter;
					iter->next = tmp[2];
				}
				else
				{
					tmp[3]->next = iter->next;
					tmp[3]->next->next = iter;
					tmp[3]->next->next->next = tmp[2];
				}
			}
			else
			{
				tmp[3] = iter;
				iter = iter->next;
			}
			ft_putstr_fd("\n", 2);
		}
	}
}

char	*path_join(const char *str1, const char *str2)
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

void	lstfadd(t_list **files, struct dirent *file, char *path)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_file	*content;

	tmp2 = *files;

	tmp = ft_lstnew(NULL, 0);
	tmp->content = (t_file *)malloc(sizeof(t_file));
	content = tmp->content;
	content->name = (struct dirent *)malloc(sizeof(struct dirent));
	ft_memcpy((void *)content->name, (void *)file, sizeof(struct dirent));
	content->path = path;
	content->doss = 0;
	if (tmp2)
	{
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
	}
	else
		*files = tmp;
}

void	lstffree(t_list *input)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_file	*content;

	tmp = input;
	tmp2 = NULL;

	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		content = tmp2->content;
		ft_memdel((void **)&content->name);
		ft_memdel((void **)&content->prop);
		ft_memdel((void **)&content);
		ft_memdel((void **)&tmp2);
	}
}

void	elemright(mode_t	mode)
{
	rightuser(mode);
	rightgroup(mode);
	rightother(mode);
	ft_putchar('\t');
}

void	rightuser(mode_t	mode)
{
	char	str[4];

	str[3] = '\0';
	str[0] = (mode & S_IRUSR) ? 'r' : '-';
	str[1] = (mode & S_IWUSR) ? 'w' : '-';
	if (mode & S_IXUSR)
	{
		str[2] = (mode & S_ISUID) ? 's' : 'x';
	}
	else
	{
		str[2] = (mode & S_ISUID) ? 'S' : '-';
	}
	ft_putstr(str);
}

void	rightgroup(mode_t	mode)
{
	char	str[4];

	str[3] = '\0';
	str[0] = (mode & S_IRGRP) ? 'r' : '-';
	str[1] = (mode & S_IWGRP) ? 'w' : '-';
	if (mode & S_IXGRP)
	{
		str[2] = (mode & S_ISGID) ? 's' : 'x';
	}
	else
	{
		str[2] = (mode & S_ISGID) ? 'S' : '-';
	}
	ft_putstr(str);
}

void	rightother(mode_t	mode)
{
	char	str[4];

	str[3] = '\0';
	str[0] = (mode & S_IROTH) ? 'r' : '-';
	str[1] = (mode & S_IWOTH) ? 'w' : '-';
	if (mode & S_IXOTH)
	{
		str[2] = (mode & S_ISVTX) ? 't' : 'x';
	}
	else
	{
		str[2] = (mode & S_ISVTX) ? 'T' : '-';
	}
	ft_putstr(str);
}

char	*elemtype(t_file	*content)
{
	if (S_ISREG(content->prop->st_mode))
		return ("-");
	else if (S_ISDIR(content->prop->st_mode))
		return ("d");
	else if (S_ISCHR(content->prop->st_mode))
		return ("c");
	else if (S_ISBLK(content->prop->st_mode))
		return ("b");
	else if (S_ISFIFO(content->prop->st_mode))
		return ("p");
	else if (S_ISLNK(content->prop->st_mode))
		return ("l");
	else if (S_ISSOCK(content->prop->st_mode))
		return ("s");
	return ("U");
}

void	elemname(t_file *line, t_flags *flags)
{
	char	*pathfile;
	char	*link;
	char	*type;

	type = elemtype(line);
	ft_putstr(line->name->d_name);
	if (flags->l && type[0] == 'l')
	{
		pathfile = path_join(line->path, line->name->d_name);
		link = ft_strnew(1025);
		if (0 > readlink(pathfile, link, sizeof(link)))
		{
			ft_putstr_fd(flags->exec, 2);
			ft_putstr_fd(" :", 2);
			ft_putstr_fd("\033[31m link error ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\033[0m\n", 2);
		}
		else
		{
			ft_putstr(" -> ");
			ft_putstr(link);
		}
		ft_strdel(&link);
		ft_strdel(&pathfile);
	}
	ft_putchar('\n');
}

void	elemowner(t_file *line, t_flags *flags)
{
	struct passwd *usr;
	struct group *grp;

	usr = getpwuid(line->prop->st_uid);
	grp = getgrgid(line->prop->st_gid);
	if (usr)
		ft_putstr(usr->pw_name);
	else
		ft_putllong((long long)line->prop->st_uid);
	ft_putchar(' ');
	if (grp)
		ft_putstr(grp->gr_name);
	else
		ft_putllong((long long)line->prop->st_gid);
	ft_putchar(' ');
}

void	elemsize(t_file	*line)
{
	if (S_ISCHR(line->prop->st_mode) || S_ISBLK(line->prop->st_mode))
	{
		ft_putnbr(major(line->prop->st_rdev));
		ft_putstr(", ");
		ft_putnbr(minor(line->prop->st_rdev));
		ft_putchar(' ');
	}
	else
	{
		ft_putllong(line->prop->st_size);
		ft_putchar('\t');
	}
}

void	printline(t_list *line, t_flags *flags)
{
	t_file	*cont;

	cont = line->content;
	if (cont->name->d_name[0] != '.' || flags->a == 1)
	{
		if (cont->error)
		{
			ft_putstr_fd(flags->exec, 2);
			ft_putstr_fd(": cannot access ", 2);
			ft_putstr_fd(cont->path, 2);
			ft_putstr_fd("/", 2);
			ft_putstr_fd(cont->name->d_name, 2);
			ft_putstr_fd(": ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\e[0m\n", 2);
		}
		else
		{
			if (flags->s)
			{
				ft_putllong(cont->prop->st_blocks);
				ft_putchar(' ');
			}
			if (flags->l)
			{
				ft_putstr(elemtype(cont));
				elemright(cont->prop->st_mode);
				ft_putnbr((int)cont->prop->st_nlink);
				ft_putchar(' ');
				elemowner(cont, flags);
				elemsize(cont);
				print_date(cont->prop->st_mtime);
			}
			elemname(cont, flags);
		}
	}
}

void	print_date(time_t date)
{
	char	*str1;
	char	*str2;
	time_t	actualtime;

	actualtime = time(0);
	str1 = ctime(&date);
	if ((actualtime - 15778463) > date || actualtime < date)
	{
		str2 = ft_strnew(6);
		str2 = ft_strsub(str1, 20, 4);
		str1 = ft_strsub(str1, 4, 6);
		str1 = ft_strjoin(str1, "  ");
		str1 = ft_strjoin(str1, str2);
		ft_memdel((void **)&str2);
	}
	else
		str1 = ft_strsub(str1, 4, 12);
	str1[12] = '\0';
	ft_putstr(str1);
	ft_putchar(' ');
	ft_memdel((void **)&str1);
}

void	printtotal(t_list *files, t_flags *flags)
{
	t_list		*tmp;
	long long	total;
	t_file		*cont;

	tmp = files;
	total = 0;
	if (flags->l || flags->s)
	{
		ft_putstr("total ");
		while (tmp)
		{
			cont = tmp->content;
			if (flags->a == 1 || cont->name->d_name[0] != '.')
				total = total + cont->prop->st_blocks;
			tmp = tmp->next;
		}
		ft_putllong(total);
		ft_putstr("\n");
	}
}

int		list(char *path, t_flags *flags)
{
	t_list			*files;
	DIR				*dir;
	t_list			*tmp;
	struct	dirent	*tmp2;
	char			*tmppath;

	files	= NULL;

	dir = opendir(path);
	if (dir == NULL)
	{
		ft_putstr_fd(flags->exec, 2);
		ft_putstr_fd(": cannot open directory '", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("': ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return errno;
	}
	while ((tmp2 = readdir(dir)) != NULL)
		lstfadd(&files, tmp2, path);
	ft_putstr_fd("\e[0m", 2);
	//sort_name(&files, flags);
	if (flags->R)
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	tmp = files;
	while (tmp)
	{
		insp_file(tmp, flags);
		tmp = tmp->next;
	}
	printtotal(files, flags);
	tmp = files;
	while (tmp)
	{
		printline(tmp ,flags);
		tmp = tmp->next;
	}

	tmp = files;
	while (tmp && flags->R)
	{
		t_file *cont;

		cont = tmp->content;
		if (cont->doss)
		{
			if (ft_strlen(cont->name->d_name))
			{
				ft_putstr("\n");
				list(tmppath = path_join(path, cont->name->d_name), flags);
				ft_strdel(&tmppath);
			}
		}
		tmp = tmp->next;
	}
	closedir(dir);
	lstffree(files);
	return 0;
}

int		insp_file(t_list *file, t_flags *flags)
{
	char	*pathfile;
	t_file	*cont;

	cont = file->content;
	pathfile = path_join(cont->path, cont->name->d_name);
	cont->prop = (struct stat *)malloc(sizeof(struct stat));
	if (lstat(pathfile, cont->prop) < 0)
	{
		cont->error = 1;
		return 1;
	}
	cont->doss = 0;
	if ((ft_strequ(cont->name->d_name, "..") == 0) &&
			(ft_strequ(cont->name->d_name, ".") == 0))
		if (S_ISDIR(cont->prop->st_mode))
			cont->doss = 1;
	ft_strdel(&pathfile);
	cont->error = 0;
	return 0;
}
