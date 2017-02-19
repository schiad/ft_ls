/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:59:13 by schiad            #+#    #+#             */
/*   Updated: 2017/02/19 13:47:32 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		parse_input(int argc, char **argv, t_options *options)
{
	t_list	*files;

	init_options(options);
	if (parse_options(argc, argv, options) > 0)
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
		if (((t_file*)tmp->content)->error)
			printerror(tmp, options);
		tmp = tmp->next;
	}
	print_elems(files, options, multiple);
	if (!files)
		list(".", options, -1);
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
			if (argv[i][0] == '-' && argv[i][1] && error == 0)
			{
				error = exist_option(argv[i], argv[0]);
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
