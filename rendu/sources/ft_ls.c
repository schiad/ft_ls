/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:52:13 by schiad            #+#    #+#             */
/*   Updated: 2017/02/18 14:15:24 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int argc, char **argv)
{
	t_options	*options;

	options = (t_options *)malloc(sizeof(t_options));
	parse_input(argc, argv, options);
	ft_memdel((void **)&options);
	return (0);
}

void	init_options(t_options *options)
{
	options->a = 0;
	options->l = 0;
	options->r = 0;
	options->s = 0;
	options->bigr = 0;
	options->t = 0;
}

int		parse_input(int argc, char **argv, t_options *options)
{
	t_list	*files;

	init_options(options);
	if (parse_options(argc, argv, options))
		return (1);
	files = parse_files(argc, argv);
	if (files)
		sort_name(files, options);
	inspect_type(files, options);
	return (0);
}

void	inspect_type(t_list *files, t_options *options)
{
	t_list	*tmp;
	int		multiple;

	insp_file(files, 1);
	multiple = 0;
	if (files && files->next)
		multiple = 1;
	tmp = files;
	while (tmp)
	{
		if (tmp != files && ((t_file*)tmp->content)->dir)
			ft_putstr("\n");
		if (((t_file*)tmp->content)->dir)
			list(((t_file*)tmp->content)->name->d_name, options, multiple);
		if (!((t_file*)tmp->content)->dir)
			printline(tmp, options, 1);
		tmp = tmp->next;
	}
	if (!files)
		list(".", options, 0);
}

t_list	*parse_files(int argc, char **argv)
{
	int				i;
	t_list			*files;
	struct dirent	*tmpdir;
	int				option;

	files = NULL;
	i = 1;
	option = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == '\0'
				&& option)
			option = 0;
		else if (!option || argv[i][0] != '-' ||
			(argv[i][0] == '-' && argv[i][1] == '\0'))
		{
			tmpdir = (struct dirent *)malloc(sizeof(struct dirent));
			ft_strcpy(tmpdir->d_name, argv[i]);
			lstfadd(&files, tmpdir, ".");
		}
		i++;
	}
	return (files);
}

int		exist_option(char *option, char *exec)
{
	int	i;

	i = 1;
	while (option[i])
	{
		if (!ft_strchr("alrsRt", option[i]))
		{
			ft_putstr(exec);
			ft_putstr(": illegal option -- ");
			ft_putchar(option[i]);
			ft_putstr("\nusage : ft_ls [-Ralrst] [file ...]\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int		parse_options(int argc, char **argv, t_options *options)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	options->exec = argv[0];
	while (++i < argc)
	{
		if (argv[i][1] == '-')
			i = argc;
		else
		{
			if (argv[i][0] == '-' && argv[i][1] && !error)
			{
				error += exist_option(argv[i], argv[0]);
				options->a = (ft_strchr(argv[i], 'a')) ? 1 : options->a;
				options->l = (ft_strchr(argv[i], 'l')) ? 1 : options->l;
				options->r = (ft_strchr(argv[i], 'r')) ? 1 : options->r;
				options->s = (ft_strchr(argv[i], 's')) ? 1 : options->s;
				options->bigr = (ft_strchr(argv[i], 'R')) ? 1 : options->bigr;
				options->t = (ft_strchr(argv[i], 't')) ? 1 : options->t;
			}
		}
	}
	return (error);
}

long	compare_time(t_list *tmp)
{
	long	diff;

	diff = ((t_file*)tmp->content)->prop->st_mtime -
	((t_file*)tmp->next->content)->prop->st_mtime;
	if (!diff)
		diff = NSEC_F - NSEC_S;
	if (!diff)
		diff = ft_strcmp(((t_file*)tmp->content)->name->d_name,
		((t_file*)tmp->next->content)->name->d_name);
	return (diff);
}

void	sort_time(t_list *files, t_options *options)
{
	long	diff;
	int		ok;
	t_list	*tmp;
	t_file	*sort;

	ok = 0;
	while (!ok)
	{
		ok = 1;
		tmp = files;
		while (tmp->next)
		{
			sort = tmp->content;
			diff = compare_time(tmp);
			diff = (options->r) ? diff : -diff;
			if (diff > 0)
			{
				tmp->content = tmp->next->content;
				tmp->next->content = sort;
				ok = 0;
			}
			tmp = tmp->next;
		}
	}
}

void	sort_name(t_list *files, t_options *options)
{
	int		diff;
	int		ok;
	t_list	*tmp;
	t_file	*sort;

	ok = 0;
	while (!ok)
	{
		ok = 1;
		tmp = files;
		while (tmp->next)
		{
			sort = tmp->content;
			diff = ft_strcmp(((t_file*)tmp->content)->name->d_name,
					((t_file*)tmp->next->content)->name->d_name);
			diff = (options->r) ? -diff : diff;
			if (diff > 0)
			{
				tmp->content = tmp->next->content;
				tmp->next->content = sort;
				ok = 0;
			}
			tmp = tmp->next;
		}
	}
}

char	*path_join(const char *str1, const char *str2)
{
	char	*result;
	int		i;
	int		j;

	result = ft_strnew(ft_strlen(str1) + ft_strlen(str2) + 1);
	i = 0;
	j = 0;
	while (str1[i])
	{
		if (!(str1[i] == '/' && (str1[i + 1] == '/' || str1[i + 1] == '\0')))
			result[j++] = str1[i];
		i++;
	}
	result[j] = '/';
	j++;
	i = 0;
	if (str2[0] == '/')
		j = 0;
	while (str2[i])
	{
		result[j++] = str2[i];
		i++;
	}
	result[j] = '\0';
	return (result);
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
	content->dir = 0;
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

void	elemright(mode_t mode)
{
	rightuser(mode);
	rightgroup(mode);
	rightother(mode);
	ft_putchar(' ');
}

void	rightuser(mode_t mode)
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

void	rightgroup(mode_t mode)
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

void	rightother(mode_t mode)
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

char	*elemtype(t_file *content)
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

void	elemname(t_file *line, t_options *options)
{
	char	*pathfile;
	char	link[1026];
	char	*type;

	type = elemtype(line);
	ft_putstr(line->name->d_name);
	if (options->l && type[0] == 'l')
	{
		ft_memset(link, '\0', 1026);
		pathfile = path_join(line->path, line->name->d_name);
		if (0 > readlink(pathfile, link, sizeof(link)))
		{
			ft_putstr_fd(options->exec, 2);
			ft_putstr_fd(" : link error", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd(":\n", 2);
		}
		else
		{
			ft_putstr(" -> ");
			ft_putstr(link);
		}
		ft_strdel(&pathfile);
	}
	ft_putchar('\n');
}

void	elemowner(t_file *line)
{
	struct passwd	*usr;
	struct group	*grp;

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

void	elemsize(t_file *line)
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
		ft_putchar(' ');
	}
}

void	printerror(t_list *line, t_options *options)
{
	ft_putstr_fd(options->exec, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(((t_file*)line->content)->name->d_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("\n", 2);
}

void	printline(t_list *line, t_options *options, int bypass)
{
	if (((t_file*)line->content)->name->d_name[0] != '.' || options->a == 1 ||
			bypass)
	{
		if (((t_file*)line->content)->error)
			printerror(line, options);
		else
		{
			if (options->s)
			{
				ft_putllong(((t_file*)line->content)->prop->st_blocks);
				ft_putchar(' ');
			}
			if (options->l)
			{
				ft_putstr(elemtype(((t_file*)line->content)));
				elemright(((t_file*)line->content)->prop->st_mode);
				ft_putnbr((int)((t_file*)line->content)->prop->st_nlink);
				ft_putchar(' ');
				elemowner(((t_file*)line->content));
				elemsize(((t_file*)line->content));
				print_date(((t_file*)line->content)->prop->st_mtime);
			}
			elemname(((t_file*)line->content), options);
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

void	printtotal(t_list *files, t_options *options)
{
	t_list		*tmp;
	long long	total;
	t_file		*cont;

	tmp = files;
	total = 0;
	if (options->l || options->s)
	{
		ft_putstr("total ");
		while (tmp)
		{
			cont = tmp->content;
			if (options->a == 1 || cont->name->d_name[0] != '.')
				total = total + cont->prop->st_blocks;
			tmp = tmp->next;
		}
		ft_putllong(total);
		ft_putstr("\n");
	}
}

void	print_link_error(char *exec, char *name)
{
	ft_putstr_fd(exec, 2);
	ft_putstr_fd(" : link error ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

void	parse_links(t_list *line, t_options *options)
{
	t_list	*tmp;
	char	*type;
	char	link[1026];
	char	*pathfile;

	tmp = line;
	if (options->l)
		while (tmp)
		{
			type = elemtype(((t_file*)tmp->content));
			if (type[0] == 'l')
			{
				ft_memset(link, '\0', 1026);
				pathfile = path_join(((t_file*)tmp->content)->path,
						((t_file*)tmp->content)->name->d_name);
				if (0 > readlink(pathfile, link, sizeof(link)))
				{
					print_link_error(options->exec,
							((t_file*)tmp->content)->name->d_name);
				}
				ft_strdel(&pathfile);
			}
			tmp = tmp->next;
		}
}

int		list(char *path, t_options *options, int header)
{
	t_list			*files;
	DIR				*dir;
	t_list			*tmp;
	struct dirent	*tmp2;
	char			*tmppath;

	files = NULL;
	dir = opendir(path);
	if (dir == NULL)
	{
		ft_putstr_fd(options->exec, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (errno);
	}
	while ((tmp2 = readdir(dir)) != NULL)
		lstfadd(&files, tmp2, path);
	if (options->bigr || header)
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	insp_file(files, 0);
	printtotal(files, options);
	parse_links(files, options);
	if (options->t)
		sort_time(files, options);
	else
		sort_name(files, options);
	tmp = files;
	while (tmp)
	{
		printline(tmp, options, 0);
		tmp = tmp->next;
	}
	tmp = files;
	while (tmp && options->bigr)
	{
		if (((t_file*)tmp->content)->dir)
		{
			if (ft_strlen(((t_file*)tmp->content)->name->d_name))
			{
				ft_putstr("\n");
				list(tmppath = path_join(path,
							((t_file*)tmp->content)->name->d_name),
						options, header);
				ft_strdel(&tmppath);
			}
		}
		tmp = tmp->next;
	}
	closedir(dir);
	lstffree(files);
	return (0);
}

int		is_parent_local(char *str)
{
	int	result;

	result = 0;
	result += (int)ft_strequ(str, "..");
	result += (int)ft_strequ(str, ".");
	return (result);
}

int		insp_file(t_list *file, int bypass)
{
	char	*pathfile;
	t_list	*tmp;
	int		errors;

	errors = 0;
	tmp = file;
	while (tmp)
	{
		pathfile = path_join(((t_file*)tmp->content)->path,
				((t_file*)tmp->content)->name->d_name);
		((t_file*)tmp->content)->prop =
			(struct stat *)malloc(sizeof(struct stat));
		((t_file*)tmp->content)->error = 0;
		if (lstat(pathfile, ((t_file*)tmp->content)->prop) < 0)
			((t_file*)tmp->content)->error = 1;
		((t_file*)tmp->content)->dir = 0;
		if (!is_parent_local(((t_file*)tmp->content)->name->d_name) || bypass)
			if (S_ISDIR(((t_file*)tmp->content)->prop->st_mode))
				((t_file*)tmp->content)->dir = 1;
		ft_strdel(&pathfile);
		errors += ((t_file*)tmp->content)->error;
		tmp = tmp->next;
	}
	return (errors);
}
