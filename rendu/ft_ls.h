

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
	int		a;
	int		l;
	int		r;
	int		R;
	int		t;
}			t_flags;

typedef	struct		s_file
{
	struct	stat	*prop;
	struct	dirent	*name;
	struct	s_file	*next;
	int		doss;
	char		*path;
}			t_file;

t_file  *ft_lstfadd(t_file *input, struct dirent *file, char *path);
void    ft_lstffree(t_file *input);
int	ft_list(char *path, t_flags *flags);
void    ft_elemright(mode_t	mode);
void    ft_rightuser(mode_t mode);
void    ft_rightgroup(mode_t mode);
void    ft_rightother(mode_t mode);
char    *ft_elemtype(t_file *line);
void    ft_elemowner(t_file *line, t_flags *flags);
void    ft_printline(t_file *line, t_flags *flags);
int		ft_insp_file(t_file *file);
void	ft_elemname(t_file *line);
char	*ft_path_join(const char *str1, const char *str2);

#endif
