/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 20:19:34 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/06 22:09:28 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	free_content(t_ls *adr_content)
{
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
		|| !(content.u_name = get_uname(uid_t uid))
		|| !(content.g_name = get_gname(gid_t gid))
		|| !(content.rights = get_rights())
		|| !(content.type = get_type())
		|| !(content.time = get_time()))
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
