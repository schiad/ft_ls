

#ifndef FT_LS_H
# define FT_LS_H

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

typedef	struct		s_flags
{
	int				a;
	int				l;
	int				r;
	int				s;
	int				R;
	int				t;
	char			*exec;
}					t_flags;

typedef	struct		s_file
{
	struct	stat	*prop;
	struct	dirent	*name;
	struct	s_file	*next;
	int				doss;
	char			*path;
	int				error;
}					t_file;

void    lstfadd(t_list **files, struct dirent *file, char *path);
void    lstffree(t_list *input);
int		list(char *path, t_flags *flags);
void    elemright(mode_t	mode);
void    rightuser(mode_t mode);
void    rightgroup(mode_t mode);
void    rightother(mode_t mode);
char    *elemtype(t_file *line);
void    elemowner(t_file *line, t_flags *flags);
void    printline(t_list *line, t_flags *flags);
void	print_date(time_t date);
void    printtotal(t_list *files, t_flags *flags);
int		insp_file(t_list *file, t_flags *flags);
void	elemname(t_file *line, t_flags *flags);
char	*path_join(const char *str1, const char *str2);
void	sort_name(t_list *file, t_flags *flags);

#endif
