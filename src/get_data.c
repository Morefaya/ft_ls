/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 20:19:34 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/18 13:00:24 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	free_content(t_ls *adr_content)
{
	free(adr_content->name);
	free(adr_content->u_name);
	free(adr_content->g_name);
	free(adr_content->rights);
	free(adr_content->time);
}

static t_list	*get_link_list(struct dirent *f_dirent, struct stat *f_stat)
{
	t_ls	content;
	t_list	*lst;

	if (!f_stat || !f_dirent)
		return (NULL);
	errno = 0;
	content.nb_hlink = (int)(f_stat->st_nlink);
	content.size = (int)(f_stat->st_size);
	content.nb_blk = (int)(f_stat->st_blocks);
	if (!(content.name = ft_strdup(f_dirent->d_name))
		|| !(content.u_name = get_uname(st_uid))
		|| !(content.g_name = get_gname(st_gid))
		|| !(content.rights = get_rights(f_stat, path))
		|| !(content.type = get_type(f_stat))
		|| !(content.time = get_time(st_mtime)))
		return (NULL);
	if (!(lst = lst_new(&content, sizeof(content))))
	{
		free_content(&content);
		return (NULL);
	}
	return (lst);
}


t_list		*get_data(t_list **list, DIR *f_dir)
{
	t_list		*lst_tmp;
	struct dirent	*f_dirent;
	struct stat	*f_stat;

	errno = 0;
	while ((f_dirent = readdir(f_dir)))
	{
		if (lstat((const char*)(f_dirent->d_name), f_stat) == -1)
		{
			ft_putendl(strerror(errno));
			return (NULL);
		}
		ft_lstadd(list, lst_tmp);
	}
}
