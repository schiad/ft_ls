/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:14:51 by schiad            #+#    #+#             */
/*   Updated: 2017/02/18 20:31:53 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# ifdef __linux__
#  define NSEC_F ((t_file*)tmp->content)->prop->st_mtim.tv_nsec
#  define NSEC_S ((t_file*)tmp->next->content)->prop->st_mtim.tv_nsec
# endif

# if defined(__APPLE__) || defined(__MACH__)
#  define NSEC_F ((t_file*)tmp->content)->prop->st_mtimespec.tv_nsec
#  define NSEC_S ((t_file*)tmp->next->content)->prop->st_mtimespec.tv_nsec
# endif

# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <errno.h>
# include "libft.h"

typedef	struct		s_options
{
	int				a;
	int				l;
	int				r;
	int				s;
	int				bigr;
	int				t;
	char			*exec;
}					t_options;

typedef struct		s_file
{
	struct stat		*prop;
	struct dirent	*name;
	int				dir;
	char			*path;
	char			*str_error;
	int				error;
}					t_file;

int					parse_options(int argc, char **argv, t_options *options);
t_list				*parse_files(int argc, char **argv);
int					parse_input(int argc, char **argv, t_options *options);
void				parse_links(t_list *line, t_options *options);
void				inspect_type(t_list *files, t_options *options);
void				init_options(t_options *options);
int					list(char *path, t_options *options, int header);
void				printline(t_list *line, t_options *options, int bypass);
void				call_recursif(t_list *files, t_options *options,
		int header);
void				printline(t_list *line, t_options *options, int bypass);
void				printerror(t_list *line, t_options *options);
void				print_date(time_t date);
void				printtotal(t_list *files, t_options *options);
void				print_link_error(char *exec, char *name);
void				printdirerror(char *exec, char *path);
void				elemright(mode_t mode);
char				*elemtype(t_file *line);
void				elemowner(t_file *line);
void				elemname(t_file *line, t_options *options);
void				rightuser(mode_t mode);
void				rightgroup(mode_t mode);
void				rightother(mode_t mode);
void				print_elems(t_list *files, t_options *options,
		int mult);
void				print_list(t_list *files, t_options *options,
		int header);
int					exist_option(char *option, char *exec);
int					insp_file(t_list *file, int bypass);
void				lstfadd(t_list **files, struct dirent *file, char *path);
void				lstffree(t_list *input);
void				elemsize(t_file *line);
long				compare_time(t_list *tmp);
int					is_parent_local(char *str);
char				*path_join(const char *str1, const char *str2);
void				sort_name(t_list *file, t_options *options);
void				sort_time(t_list *file, t_options *options);

#endif
