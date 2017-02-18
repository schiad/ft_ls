/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:49:56 by schiad            #+#    #+#             */
/*   Updated: 2017/02/18 20:17:02 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	elemright(mode_t mode)
{
	rightuser(mode);
	rightgroup(mode);
	rightother(mode);
	ft_putchar(' ');
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
		if (0 <= readlink(pathfile, link, sizeof(link)))
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
