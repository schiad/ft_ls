/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:56:59 by schiad            #+#    #+#             */
/*   Updated: 2017/02/28 18:07:59 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int argc, char **argv)
{
	t_options	options;
	int			ret;

	ret = parse_input(argc, argv, &options);
	return (ret);
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

void	call_recursif(t_list *files, t_options *options, int header)
{
	char	*tmppath;
	t_list	*tmp;
	char	*name;
	int		ok;

	tmp = files;
	while (tmp && options->bigr)
	{
		ok = 0;
		name = ((t_file*)tmp->content)->name->d_name;
		if (name[0] != '.' || options->a)
			ok = 1;
		if (((t_file*)tmp->content)->dir && ok)
		{
			if (ft_strlen(((t_file*)tmp->content)->name->d_name))
			{
				ft_putstr("\n");
				list(tmppath = path_join(((t_file*)tmp->content)->path,
							((t_file*)tmp->content)->name->d_name),
						options, header);
				ft_strdel(&tmppath);
			}
		}
		tmp = tmp->next;
	}
}

int		list(char *path, t_options *options, int header)
{
	t_list			*files;
	DIR				*dir;
	struct dirent	*tmp2;

	files = NULL;
	dir = opendir(path);
	if (dir == NULL)
	{
		printdirerror(options->exec, path);
		return (0);
	}
	while ((tmp2 = readdir(dir)) != NULL)
		lstfadd(&files, tmp2, path);
	if ((options->bigr || header) && header > 0)
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	print_list(files, options, 1);
	closedir(dir);
	lstffree(files);
	return (0);
}
