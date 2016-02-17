/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:28:40 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/06 21:29:01 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdlib.h>
# include <sys/acl.h>
# include <sys/xattr.h>

typedef struct	s_ls
{
	char		*name;
	int		nb_hlink;
	int		nb_blk;
	char		type;
	char		*rights;
	char		*u_name;
	char		*g_name;
	size_t		size;
	char		*time;
}				t_ls;

char	*get_uname(uid_t uid);
char	*get_gname(gid_t gid);
char	*get_rights(struct stat *f_stat, char *path);
char	get_type(struct stat *f_stat);
char	*get_time(time_t time);
char	*path_builder(char *path, char *dir_name);

/*fait une liste de liste pour laffichage ls sans l*/

#endif
