/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:48:16 by schiad            #+#    #+#             */
/*   Updated: 2017/02/19 13:47:52 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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

void	print_elems(t_list *files, t_options *options, int mult)
{
	t_list	*tmp;

	tmp = files;
	while (tmp)
	{
		if (!((t_file*)tmp->content)->dir &&
				!((t_file*)tmp->content)->error)
			printline(tmp, options, 1);
		tmp = tmp->next;
	}
	tmp = files;
	while (tmp)
	{
		if (tmp != files && ((t_file*)tmp->content)->dir)
			ft_putstr("\n");
		if (((t_file*)tmp->content)->dir &&
				!((t_file*)tmp->content)->error)
			list(((t_file*)tmp->content)->name->d_name,
					options, mult);
		tmp = tmp->next;
	}
}

void	print_list(t_list *files, t_options *options, int header)
{
	t_list	*tmp;

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
	call_recursif(files, options, header);
}
