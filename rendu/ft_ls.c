#include <dirent.h>
#include "ft_ls.h"
#include "./libft/includes/libft.h"

int	main(int argc, char **argv)
{
	t_flags	*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	flags->l = 1;
	flags->R = 1;
	flags->s = 1;
	flags->exec = argv[0];
	if (argc != 2)
		ft_list(".", flags);
	else
		ft_list(argv[1], flags);
	ft_memdel((void **)&flags);
	return 0;
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
		if (!(tmp->name = (struct dirent *)malloc(sizeof(struct dirent))))
			return ((void *)NULL);
		ft_memcpy((void *)tmp->name, (void *)file, sizeof(struct dirent));
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
		ft_memdel((void **)&tmp2->name);
		ft_memdel((void **)&tmp2->prop);

		ft_memdel((void **)&tmp2);
	}
}

void	ft_elemright(mode_t	mode)
{
	ft_rightuser(mode);
	ft_rightgroup(mode);
	ft_rightother(mode);
	ft_putchar('\t');
}

void	ft_rightuser(mode_t	mode)
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

void	ft_rightgroup(mode_t	mode)
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

void	ft_rightother(mode_t	mode)
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
	return ("U");
}

void	ft_elemname(t_file *line, t_flags *flags)
{
	char	*pathfile;
	char	*link;
	char	*type;

	type = ft_elemtype(line);
	ft_putstr(line->name->d_name);
	if (flags->l && type[0] == 'l')
	{
		pathfile = ft_path_join(line->path, line->name->d_name);
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

void	ft_elemowner(t_file *line, t_flags *flags)
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

void	ft_elemsize(t_file	*line)
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

void	ft_printline(t_file	*line, t_flags	*flags)
{
	if (line->error)
	{
		ft_putstr_fd(flags->exec, 2);
		ft_putstr_fd(": cannot access ", 2);
		ft_putstr_fd(line->path, 2);
		ft_putstr_fd("/", 2);
		ft_putstr_fd(line->name->d_name, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\e[0m\n", 2);
	}
	else
	{
		if (flags->l)
		{
			if (flags->s)
			{
				ft_putllong(line->prop->st_blocks);
				ft_putchar(' ');
			}
			ft_putstr(ft_elemtype(line));
			ft_elemright(line->prop->st_mode);
			ft_putnbr((int)line->prop->st_nlink);
			ft_putchar(' ');
			ft_elemowner(line, flags);
			ft_elemsize(line);
			ft_print_date(line->prop->st_mtime);
		}
		ft_elemname(line, flags);
	}
}

void	ft_print_date(time_t date)
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

void	ft_printtotal(t_file *files, t_flags *flags)
{
	t_file		*tmp;
	long long	total;

	tmp = files;
	total = 0;
	if (flags->l)
	{
		ft_putstr("total ");
		while (tmp)
		{
			if (tmp->name->d_name[0] != '.')
				total = total + tmp->prop->st_blocks;
			tmp = tmp->next;
		}
		ft_putllong(total);
		ft_putstr("\n");
	}
}

int	ft_list(char *path, t_flags *flags)
{
	t_file			*files;
	DIR				*dir;
	t_file			*tmp;
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
		files = ft_lstfadd(files, tmp2, path);
	if (flags->R)
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	tmp = files;
	while (tmp)
	{
		ft_insp_file(tmp, flags);
		tmp = tmp->next;
	}
	ft_printtotal(files, flags);
	tmp = files;
	while (tmp)
	{
		if (!tmp->error)
			ft_printline(tmp ,flags);
		tmp = tmp->next;
	}

	tmp = files;
	while (tmp && flags->R)
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
	return 0;
}

int		ft_insp_file(t_file *file, t_flags *flags)
{
	char *pathfile;

	pathfile = ft_path_join(file->path, file->name->d_name);
	file->prop = (struct stat *)malloc(sizeof(struct stat));
	if (lstat(pathfile, file->prop) < 0)
	{
		file->error = 1;
		return 1;
	}
	file->doss = 0;
	if ((ft_strequ(file->name->d_name, "..") == 0) &&
			(ft_strequ(file->name->d_name, ".") == 0))
		if (S_ISDIR(file->prop->st_mode))
			file->doss = 1;
	ft_strdel(&pathfile);
	file->error = 0;
	return 0;
}
