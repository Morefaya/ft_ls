/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:53:04 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/24 14:20:39 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_uname(uid_t uid)
{
	struct passwd	*pwd;
	char			*user;

	errno = 0;
	if (!(pwd = getpwuid(uid)))
	{
		ft_putendl(strerror(errno));
		return (NULL);
	}
	if (!(user = ft_strdup((char*)(pwd->pw_name))))
		return (NULL);
	return (user);
}

char	*get_gname(gid_t gid)
{
	struct group	*crew;
	char			*grp;

	errno = 0;
	if (!(crew = getgrgid(gid)))
	{
		ft_putendl(strerror(errno));
		return (NULL);
	}
	if (!(grp = ft_strdup((char*)(crew->gr_name))))
		return (NULL);
	return (grp);
}

char	get_type(struct stat *f_stat)
{
	if (((f_stat->st_mode) & S_IFMT) == S_IFBLK)
		return ('b');
	if (((f_stat->st_mode) & S_IFMT) == S_IFCHR)
		return ('c');
	if (((f_stat->st_mode) & S_IFMT) == S_IFDIR)
		return ('d');
	if (((f_stat->st_mode) & S_IFMT) == S_IFIFO)
		return ('p');
	if (((f_stat->st_mode) & S_IFMT) == S_IFLNK)
		return ('l');
	if (((f_stat->st_mode) & S_IFMT) == S_IFREG)
		return ('-');
	if (((f_stat->st_mode) & S_IFMT) == S_IFSOCK)
		return ('s');
	return ('\0');
}
