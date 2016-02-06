#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <errno.h>

typedef struct	s_ls
{
	char	*name;
	int	nb_link;
	char	*rights;
	char	*u_name;
	char	*g_name;
	size_t	size;
	char	*time;
}		t_ls;

#endif
