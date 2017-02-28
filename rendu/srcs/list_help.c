/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 13:49:30 by schiad            #+#    #+#             */
/*   Updated: 2017/02/28 18:01:10 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		exist_option(char *option, char *exec)
{
	int	i;

	i = 1;
	while (option[i])
	{
		if (!ft_strchr("1alrsRt", option[i]))
		{
			ft_putstr_fd(exec, 2);
			ft_putstr_fd(": illegal option -- ", 2);
			ft_putchar_fd(option[i], 2);
			ft_putstr_fd("\nusage: ft_ls [-1Ralrst] [file ...]\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
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
			(struct stat *)ft_memalloc(sizeof(struct stat));
		((t_file*)tmp->content)->error = 0;
		if (lstat(pathfile, ((t_file*)tmp->content)->prop) < 0)
			((t_file*)tmp->content)->error = 1;
		((t_file*)tmp->content)->str_error = strerror(errno);
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

void	lstfadd(t_list **files, struct dirent *file, char *path)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_file	*content;

	tmp2 = *files;
	tmp = ft_lstnew(NULL, 0);
	tmp->content = (t_file *)ft_memalloc(sizeof(t_file));
	content = tmp->content;
	content->name = (struct dirent *)ft_memalloc(sizeof(struct dirent));
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
