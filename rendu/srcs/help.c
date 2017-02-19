/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:30:53 by schiad            #+#    #+#             */
/*   Updated: 2017/02/19 12:27:02 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

long	compare_time(t_list *tmp)
{
	long	diff;

	diff = 0;
	diff = ((t_file*)tmp->next->content)->prop->st_mtime -
	((t_file*)tmp->content)->prop->st_mtime;
	if (!diff)
		diff = NSEC_F - NSEC_S;
	if (!diff)
		diff = ft_strcmp(((t_file*)tmp->content)->name->d_name,
		((t_file*)tmp->next->content)->name->d_name);
	return (diff);
}

int		is_parent_local(char *str)
{
	int	result;

	result = 0;
	result += (int)ft_strequ(str, "..");
	result += (int)ft_strequ(str, ".");
	return (result);
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
