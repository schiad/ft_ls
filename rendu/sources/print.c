/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:50:43 by schiad            #+#    #+#             */
/*   Updated: 2017/02/18 18:53:38 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	printerror(t_list *line, t_options *options)
{
	ft_putstr_fd(options->exec, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(((t_file*)line->content)->name->d_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(((t_file*)line->content)->str_error, 2);
	ft_putstr_fd("\n", 2);
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

void	printdirerror(char *exec, char *path)
{
	ft_putstr_fd(exec, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}
