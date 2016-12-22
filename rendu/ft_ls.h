

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

typedef	struct	s_file
{
	struct	stat	*prop;
	struct	dirent	*name;
	struct	s_file	*next;
	char			*path;
}				t_file;

t_file  *ft_lstfadd(t_file *input, struct dirent *file, char *path);
int		ft_list(char *path);
void	ft_insp_file(t_file *file);

#endif